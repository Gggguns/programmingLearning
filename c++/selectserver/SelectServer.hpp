#include <iostream>
#include <sys/select.h>
#include "Log.hpp"
#include "Sock.hpp"
using namespace std;

static uint16_t defaultport = 8888;
static const int fd_num_max = (sizeof(fd_set) * 8);
int defaultfd = -1;

class SelectServer
{
public:
    SelectServer(uint16_t port = defaultport) : _port(port)
    {
        // 初始化辅助数组
        for (int i = 0; i < fd_num_max; i++)
        {
            rfd_array[i] = defaultfd;
        }
    }
    ~SelectServer()
    {
        _listensock.Close();
    }
    bool Init()
    {
        _listensock.Socket();
        _listensock.Bind(_port);
        _listensock.Listen();

        return true;
    }

    void Accepter()
    {
        // 我们的连接事件就绪了
        uint16_t clientport;
        string clientip;
        int sock = _listensock.Accept(&clientip, &clientport); // 会不会阻塞在这里呢？ 不会
        if (sock < 0)
            return;
        lg(Info, "accept success, %s: %d, sock fd: %d", clientip.c_str(), clientport, sock);

        // sock -> rfd_array[]
        int pos = 1; // 第一个位置已被占
        for (; pos < fd_num_max; pos++)
        {
            if (rfd_array[pos] != defaultfd)
                continue;
            else
                break;
        }

        if (pos == fd_num_max)
        {
            lg(Warning, "server is full, close %d now!", sock);
            close(sock);
        }
        else
        {
            rfd_array[pos] = sock;
            PrintFd();
            // TODO
        }
    }

    void Recver(int fd, int pos)
    {
        // demo
        char buffer[1024];
        ssize_t n = read(fd, buffer, sizeof(buffer) - 1); // bug
        if (n > 0)
        {
            buffer[n] = 0;
            cout << "get a message: " << buffer << endl;
        }
        else if (n == 0)
        {
            lg(Info, "client quit, me too, close fd is : %d", fd);
            close(fd);
            rfd_array[pos] = defaultfd; // 本质是从select中移除
        }
        else
        {
            lg(Warning, "recv error, fd is : %d", fd);
            close(fd);
            rfd_array[pos] = defaultfd; // 本质是从select中移除
        }
    }

    void Dispatcher(fd_set rfds)
    {
        for (int i = 0; i < fd_num_max; i++)
        {
            int fd = rfd_array[i];
            if (fd == defaultfd)
                continue;

            if (FD_ISSET(fd, &rfds))
            {
                if (_listensock.Fd() == fd)
                {
                    Accepter(); // 连接管理器
                }
                else // non listensock
                {
                    Recver(fd, i);
                }
            }
        }
    }

    void Start()
    {
        int listensock = _listensock.Fd();
        rfd_array[0] = listensock; // 这里固定数组第一个位置，监听文件描述符
        for (;;)
        {
            // accept? 不能直接accept! 检测并获取listensock上面的事情，新连接到来，等价于读事件就绪
            fd_set rfds;
            FD_ZERO(&rfds);

            int maxfd = rfd_array[0];
            for (int i = 0; i < fd_num_max; i++)
            {
                if (rfd_array[i] == defaultfd)
                    continue;
                // 合法fd加入rfds
                FD_SET(rfd_array[i], &rfds);
                if (rfd_array[i] > maxfd)
                {
                    maxfd = rfd_array[i];
                    lg(Info, "max fd update, max fd is: %d", maxfd);
                }
            }

            struct timeval timeout = {5, 0};

            // rfds: 输入输出型参数， 1111 1111 -> 0000 0000
            int n = select(maxfd + 1, &rfds, nullptr, nullptr, &timeout);
            switch (n)
            {
            case 0:
                cout << "time out, timeout: " << timeout.tv_sec << "." << timeout.tv_usec << endl;
                break;
            case -1:
                cerr << "select error" << endl;
            default:
                // 有事情就绪了，TODO
                cout << "get new link!!!!" << endl;
                cout << "time out, timeout: " << timeout.tv_sec << "." << timeout.tv_usec << endl;
                Dispatcher(rfds);
                break;
            }
        }
    }

    void PrintFd()
    {
        cout << "online fd list: " << endl;
        for (int i = 0; i < fd_num_max; i++)
        {
            if (rfd_array[i] == defaultfd)
                continue;
            cout << rfd_array[i] << ' ';
        }
        cout << endl;
    }

private:
    Sock _listensock;
    uint16_t _port;
    int rfd_array[fd_num_max];
};