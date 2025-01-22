#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sstream>

#define UDP_PORT 50052
#define TCP_PORT 50051
#define SERVER_IP "127.0.0.1"

//客户端
namespace ns_client
{

    class Client {
    private:
        int tcp_socket_fd;  // TCP 套接字文件描述符
        int udp_socket_fd;  // UDP 套接字文件描述符
        std::string client_id;  // 存储从服务器接收的 client_id
        double client_latitude;     //纬度
        double client_longitude;   //经度
        int user_level;      //用户等级


        // 生成一个新的 client_id
        std::string generate_client_id() {
            static int id = 0;
            return "client_" + std::to_string(id++);
        }

        // 开始建立 TCP 连接
        void start_tcp_connect(int port) {
            while (true) {
                try {
                    // 创建 TCP 套接字
                    tcp_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
                    if (tcp_socket_fd < 0) {
                        throw std::runtime_error("Failed to create socket");
                    }

                    struct sockaddr_in server_addr;
                    server_addr.sin_family = AF_INET;
                    server_addr.sin_port = htons(port);
                    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

                    // 连接到服务器
                    if (connect(tcp_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                        throw std::runtime_error("Connection failed");
                    }

                    // 发送 client_id
                    std::string client_id_with_newline = client_id + "\n";
                    if (send(tcp_socket_fd, client_id_with_newline.c_str(), client_id_with_newline.size(), 0) == -1) {
                        throw std::runtime_error("Failed to send client_id");
                    }

                    // 发送查询请求
                    while (true) {
                        sleep(30);
                        std::string query_request = "query\n";
                        if (send(tcp_socket_fd, query_request.c_str(), query_request.size(), 0) == -1) {
                            throw std::runtime_error("Failed to send query request");
                        }

                        char buffer[1024];
                        ssize_t recv_len = recv(tcp_socket_fd, buffer, sizeof(buffer), 0);
                        if (recv_len <= 0) {
                            throw std::runtime_error("Connection closed by server");
                        }

                        std::string query_result(buffer, recv_len);
                        std::cout << client_id << " query_result: " << query_result;

                        // 发送心跳包
                        update_current_location();
                        start_heartbeat();
                        
                    }
                } catch (const std::exception& e) {
                    std::cerr << "Error: " << e.what() << ". Retrying in 5 seconds..." << std::endl;
                    close(tcp_socket_fd);
                    sleep(5);
                }
            }
        }


        // 开始发送心跳包
        void start_heartbeat() {
            std::thread([this]() {
                // 创建 UDP 套接字
                udp_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
                send_heartbeat();
                }).detach();
        }


        // 发送心跳包
        void send_heartbeat() {

            std::stringstream ss;
            // 构造心跳包数据，包含 client_id、经纬度和用户等级
            ss << client_id << " " << client_latitude << " " << client_longitude << " " << user_level;


            struct sockaddr_in server_addr;
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(UDP_PORT);
            server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


            // 发送 UDP 心跳包
            sendto(udp_socket_fd, ss.str().c_str(), ss.str().size(), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        }

        //更新客户端位置
        void update_current_location(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis_lat(-90.0, 90.0);
            std::uniform_real_distribution<> dis_lon(-180.0, 180.0);
            std::uniform_int_distribution<> dis_level(1, 100);
            client_latitude = dis_lat(gen);     
            client_longitude = dis_lon(gen);   
            user_level = dis_level(gen);
        }


    public:
        Client() {
            client_id = generate_client_id();
            update_current_location();
            //开始建立连接
            start_tcp_connect(TCP_PORT);
        }
    };

    
}
void myFunction()
{
    ns_client::Client client;
}
int main() {
    const int numThreads = 1500;  // 定义线程的数量
    std::thread threads[numThreads];  // 存储线程对象的数组

    // 创建多个线程
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(myFunction);  // 创建线程并传递参数
    }

    // 等待所有线程完成
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();  // 等待线程完成
    }


    return 0;
}