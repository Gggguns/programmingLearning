#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <memory>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <csignal>
#include <thread>
#include <chrono>
#include <random>
#include <mutex>
#include <unordered_map>
#include <utility>
#include <sstream>
#include "nanoflann.hpp"

#define UDP_PORT 50052
#define TCP_PORT 50051

namespace ns_server
{
    // 存储客户端信息的结构体，包含经纬度和用户等级
    struct ClientInfo {
        double latitude;
        double longitude;
        int user_level;
    };


    // 自定义的点云适配器类，实现必要的接口
    class PointCloudAdapter {
    public:
        PointCloudAdapter(const std::vector<std::pair<double, double>>& points) : m_points(points) {}


        // 必需的接口：获取点的数量
        inline size_t kdtree_get_point_count() const { 
            //std::cout << "kdtree_get_point_count called" << std::endl;//Debug
            std::cout << m_points.size() << std::endl;
            return m_points.size(); 
        }


        // 必需的接口：获取点的维度
        inline size_t kdtree_get_point_dim() const { 
            // std::cout << "kdtree_get_point_dim called" << std::endl;//Debug
            return 2; 
        }


        // 必需的接口：获取点的数据
        inline double kdtree_get_pt(const size_t idx, const size_t dim) const {
            // std::cout << "kdtree_get_pt called, idx: " << idx << ", dim: " << dim << std::endl;//Debug
            if (idx >= m_points.size()) {
                throw std::out_of_range("Index out of range in kdtree_get_pt");
            }
            if (dim == 0) return m_points[idx].first;
            else return m_points[idx].second;
        }

        // 可选的接口：计算边界框，对于 2D 情况
        template <class BBOX>
        bool kdtree_get_bbox(BBOX& bb) const {
            // // std::cout << "kdtree_get_bbox called" << std::endl;//Debug
            // if (m_points.empty()) return false;
            // try {
            //     //Debug
            //     std::cout << "Before setting bbox values" << std::endl;
            //     std::cout << "Address of bb: " << &bb << std::endl;
            //     std::cout << "Size of bb: " << sizeof(bb) << std::endl;
            //     // 检查 m_points 中的数据是否有效
            //     bool valid = true;
            //     int i = 0;
            //     std::cout << m_points.size() << std::endl;
            //     for (const auto& p : m_points) {
            //         std::cout << i++ << ' ';
            //         if (p.first == std::numeric_limits<double>::max() || p.first == std::numeric_limits<double>::min() ||
            //             p.second == std::numeric_limits<double>::max() || p.second == std::numeric_limits<double>::min()) {
            //             std::cerr << "Invalid data in m_points" << std::endl;
            //             valid = false;
            //             break;
            //         }
            //     }
            //     std::cout << std::endl;
            //     if (!valid) {
            //         return false;
            //     }


            //     bb[0].low = m_points.front().first;
            //     // std::cout << "Set bb[0].low: " << bb[0].low << std::endl; //Debug
            //     bb[0].high = m_points.front().first;
            //     // std::cout << "Set bb[0].high: " << bb[0].high << std::endl; //Debug
            //     bb[1].low = m_points.front().second;
            //     // std::cout << "Set bb[1].low: " << bb[1].low << std::endl;  //Debug
            //     bb[1].high = m_points.front().second;
            //     // std::cout << "Set bb[1].high: " << bb[1].high << std::endl; //Debug


            //     // std::cout << "Starting loop over m_points" << std::endl; //Debug
            //     for (const auto& p : m_points) {
            //         // std::cout << "Processing point: (" << p.first << ", " << p.second << ")" << std::endl; //Debug
            //         if (p.first < bb[0].low) {
            //             // std::cout << "Updating bb[0].low: " << p.first << std::endl;
            //             bb[0].low = p.first;
            //         }
            //         if (p.first > bb[0].high) {
            //             // std::cout << "Updating bb[0].high: " << p.first << std::endl;
            //             bb[0].high = p.first;
            //         }
            //         if (p.second < bb[1].low) {
            //             // std::cout << "Updating bb[1].low: " << p.second << std::endl;
            //             bb[1].low = p.second;
            //         }
            //         if (p.second > bb[1].high) {
            //             // std::cout << "Updating bb[1].high: " << p.second << std::endl;
            //             bb[1].high = p.second;
            //         }
            //     }
            // } catch (const std::exception& e) {
            //     std::cerr << "Exception occurred in kdtree_get_bbox: " << e.what() << std::endl;
            //     return false;
            // }


            // std::cout << "kdtree_get_bbox completed successfully" << std::endl; //Debug
            // return true;
            return false;
        }


    private:
        const std::vector<std::pair<double, double>>& m_points;
    };



    // 定义一个 KD 树的点云适配器，用于存储客户端的位置信息（经纬度）
    typedef nanoflann::KDTreeSingleIndexDynamicAdaptor<
        nanoflann::L2_Simple_Adaptor<double, PointCloudAdapter>,
        PointCloudAdapter,
        2  // 二维空间
    > KDTree;


    class Server {
    private:
        int tcp_socket_fd;  // TCP 套接字文件描述符
        int udp_socket_fd;  // UDP 套接字文件描述符
        std::unordered_map<std::string, ClientInfo> client_info_map;  // 存储客户端信息的映射表，以 client_id 为键，存储客户端信息
        std::mutex client_info_mutex;  // 用于保护 client_info_map 的互斥锁
        std::vector<std::pair<double, double>> point_cloud;  // 存储客户端位置信息的点云，用于 KD 树
        //std::unique_ptr<KDTree> kd_tree;  // KD 树，用于存储和查询客户端的位置信息
        std::unordered_map<std::string, size_t> client_index_map;  // 存储 client_id 与点云索引的映射
        std::mutex client_count_mutex;  // 互斥锁，用于保护 client_count 的操作
        int client_count = 0;  // 存储客户端连接数

        //修改连接数
        void increase_client_count(){
            client_count_mutex.lock();
            client_count++;
            client_count_mutex.unlock();
            std::cout << "Client connected. Total clients: " << client_count << std::endl;
        }

        void decrease_client_count(){
            client_count_mutex.lock();
            client_count--;
            client_count_mutex.unlock();
            //std::cout << "Client connected. Total clients: " << client_count << std::endl;
        }

        void tcp_handle_client_connection(int client_socket_fd) {
            // 处理客户端连接
            char buffer[1024];
            // 接收客户端的client_id
            ssize_t recv_len = recv(client_socket_fd, buffer, sizeof(buffer), 0);
            if (recv_len <= 0) {
                close(client_socket_fd);
                decrease_client_count();
                return;
            }
            
            std::string client_id = std::string(buffer);
            // 去除末尾的换行符
            if (!client_id.empty() && client_id.back() == '\n') {
                client_id.pop_back();
            }

            if(client_id.empty()){
                close(client_socket_fd);
                decrease_client_count();
                return;
            }

            // 增加新用户信息
            {
                std::lock_guard<std::mutex> lock(client_info_mutex);
                if(client_info_map.count(client_id) == 0){
                    increase_client_count();
                    std::cout << "New client connected: " << client_id << std::endl;
                    // 存储新客户端的初始信息
                    client_info_map[client_id] = { 0, 0, 0 };
                }
            }

            // 长连接处理循环
            while (true) {
                // 接收客户端的查询请求
                memset(buffer, 0, sizeof(buffer));
                recv_len = recv(client_socket_fd, buffer, sizeof(buffer), 0);
                
                // 如果接收出错或连接已关闭
                if (recv_len <= 0) {
                    std::cout << "Client disconnected: " << client_id << std::endl;
                    break;
                }

                // 处理查询请求
                std::string query_result;
                {
                    std::lock_guard<std::mutex> lock(client_info_mutex);
                    query_result = query_nearest_clients(client_id);
                }

                // 发送查询结果给客户端
                std::string query_result_with_newline = query_result + "\n";
                if (send(client_socket_fd, query_result_with_newline.c_str(), query_result_with_newline.size(), 0) == -1) {
                    std::cerr << "Failed to send result to client: " << client_id << std::endl;
                    break;
                }
            }

            // 关闭连接并清理
            close(client_socket_fd);
            decrease_client_count();
        }

        // 开始监听 TCP 连接
        void start_tcp_listen(int port) {
            // 创建 TCP 套接字
            tcp_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (tcp_socket_fd == -1) {
                std::cerr << "Failed to create TCP socket" << std::endl;
                return;
            }
            // 服务器地址信息结构体
            struct sockaddr_in server_addr;
            
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = INADDR_ANY;
            server_addr.sin_port = htons(port);


            // 绑定套接字到服务器地址
            if (bind(tcp_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
                std::cerr << "Failed to bind TCP socket" << std::endl;
                close(tcp_socket_fd);
                return;
            }

            // 开始监听 TCP 连接请求
            if (listen(tcp_socket_fd, 1000000) == -1) {
                std::cerr << "Failed to listen on TCP socket" << std::endl;
                close(tcp_socket_fd);
                return;
            }


            while (true) {
                // 客户端地址信息结构体
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                // 接受客户端连接
                int client_socket_fd = accept(tcp_socket_fd, (struct sockaddr*)&client_addr, &client_addr_len);
                if (client_socket_fd == -1) {
                    std::cerr << "Failed to accept TCP connection" << std::endl;
                    continue;
                }

                // 使用 std::bind 将成员函数绑定到对象实例
                std::thread client_thread(std::bind(&Server::tcp_handle_client_connection, this, client_socket_fd));
                client_thread.detach();
                
            }
        }

        void udp_handle_client_connection(char* buffer, int recv_len){
            // 将接收到的数据转换为字符串
            std::string data(buffer, recv_len);
            std::string client_id;
            double latitude, longitude;
            int user_level;
            std::istringstream iss(data);
            // 从数据中解析出 client_id、经纬度和用户等级
            if (!(iss >> client_id >> latitude >> longitude >> user_level)) {
                std::cerr << "Failed to parse UDP packet data" << std::endl;
                return;
            }
            //Debug
            //printf("%s, lat: %lf, lon: %lf, level: %d\n", client_id.c_str(), latitude, longitude, user_level);

            //存储用户数据
            {
                // 加锁，保护对 client_info_map 的访问
                std::lock_guard<std::mutex> lock(client_info_mutex);
                // 更新客户端信息
                client_info_map[client_id] = { latitude, longitude, user_level };
                // 更新 KD 树中的客户端位置信息
                update_kd_tree(client_id, latitude, longitude);
            }
        }

        // 开始监听 UDP 数据包
        void start_udp_listen(int port) {
            // 创建 UDP 套接字
            udp_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
            // 服务器地址信息结构体
            struct sockaddr_in server_addr;
            if (udp_socket_fd == -1) {
                std::cerr << "Failed to create UDP socket" << std::endl;
                return;
            }
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = INADDR_ANY;
            server_addr.sin_port = htons(port);


            // 绑定套接字到服务器地址
            if (bind(udp_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
                std::cerr << "Failed to bind UDP socket" << std::endl;
                close(udp_socket_fd);
                return;
            }


            while (true) {
                char buffer[1024];
                // 客户端地址信息结构体
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);

                // 接收 UDP 数据包
                int recv_len = recvfrom(udp_socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &client_addr_len);
                if (recv_len == -1) {
                    std::cerr << "Failed to receive UDP packet" << std::endl;
                    continue;
                }
                
                // 使用 std::bind 将成员函数绑定到对象实例
                std::thread client_thread(std::bind(&Server::udp_handle_client_connection, this, buffer, recv_len));
                client_thread.detach();
            }
        }


        // 更新 KD 树中的客户端位置信息
        void update_kd_tree(const std::string& client_id, double latitude, double longitude) {
            //std::lock_guard<std::mutex> lock(client_info_mutex);
            try {
                if (client_index_map.count(client_id) == 0) {
                    size_t index = point_cloud.size();
                    point_cloud.push_back({ latitude, longitude });
                    // std::cout << "point_cloud size :" << point_cloud.size() << std::endl;
                    client_index_map[client_id] = index;
                    // if (!kd_tree) {
                    //     // 创建新的 KD 树
                    //     PointCloudAdapter adapter(point_cloud);
                    //     kd_tree = std::make_unique<KDTree>(2, adapter);
                    // }else{
                    //     std::cout << "a1\n";
                    //     // 添加新点
                    //     kd_tree->addPoints(index, index);
                    //     std::cout << "a2\n";

                    // }
                    
                } else {
                    // 更新现有点的位置
                    size_t index = client_index_map[client_id];
                    point_cloud[index] = { latitude, longitude };
                    // 重建 KD 树
                    //PointCloudAdapter adapter(point_cloud);
                    //kd_tree = std::make_unique<KDTree>(2, adapter);
                }
            } catch (const std::exception& e) {
                std::cerr << "Exception in update_kd_tree: " << e.what() << std::endl;
            }
        }


        // 查询距离指定 client_id 最近的 10 个客户端的用户等级
        std::string query_nearest_clients(const std::string& client_id) {
            //std::lock_guard<std::mutex> lock(client_info_mutex);
            if (client_info_map.count(client_id) == 0) {
                return "";
            }

            // 建 KD 树
            PointCloudAdapter adapter(point_cloud);
            std::unique_ptr<KDTree> kd_tree = std::make_unique<KDTree>(2, adapter);

            double query_pt[2] = {client_info_map.at(client_id).latitude, client_info_map.at(client_id).longitude};
            std::vector<size_t> ret_indexes(10);
            std::vector<double> out_dists_sqr(10);
            // 创建一个结果集对象，用于存储最近邻的索引和距离
            nanoflann::KNNResultSet<double> result_set(10);
            result_set.init(&ret_indexes[0], &out_dists_sqr[0]);
            //在 KD 树中查找最近邻
            if (kd_tree) {
                try {
                    auto start_time = std::chrono::high_resolution_clock::now();
                    kd_tree->findNeighbors(result_set, query_pt, nanoflann::SearchParameters(10));
                    auto end_time = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);


                    std::vector<int> nearest_user_levels;
                    for (size_t index : ret_indexes) {
                        for (const auto& element : client_index_map) {
                            if (element.second == index) {
                                nearest_user_levels.push_back(client_info_map.at(element.first).user_level);
                                break;
                            }
                        }
                    }

                    std::string result_str;
                    for (int level : nearest_user_levels) {
                        result_str += std::to_string(level) + " ";
                    }
                    result_str += std::to_string(duration.count());  // 添加查询时间
                    return result_str;
                } catch (const std::exception& e) {
                    std::cerr << "Exception when finding neighbors: " << e.what() << std::endl;
                    return "";
                }
            }

            return "";
        }



    public:
        Server(int tcp_port, int udp_port) : client_count(0) {
            // 注册信号处理函数
            std::signal(SIGSEGV, [](int signum) {
                std::cerr << "Segmentation fault occurred!" << std::endl;
                std::exit(signum);
            });

            // 创建 TCP 监听线程
            std::thread tcp_thread(&Server::start_tcp_listen, this, tcp_port);
            // 创建 UDP 监听线程
            std::thread udp_thread(&Server::start_udp_listen, this, udp_port);

            
            // 等待 TCP 监听线程结束
            tcp_thread.join();
            // 等待 UDP 监听线程结束
            udp_thread.join();
        }
    };

    
}
int main() {
        
        // 创建服务器对象，开始监听 TCP 和 UDP 端口
        ns_server::Server server(TCP_PORT, UDP_PORT);


        return 0;
    }