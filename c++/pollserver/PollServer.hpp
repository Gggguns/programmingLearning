#include <iostream>
#include <poll.h>
#include "Log.hpp"
#include "Sock.hpp"
using namespace std;

static uint16_t defaultport = 8888;
static const int fd_num_max = (sizeof(fd_set) * 8);
int defaultfd = -1; // 不关心
int non_event = 0; // 无事件

class PollServer
{
public:
   PollServer(uint16_t port = defaultport) : _port(port)
    {
        // 初始化辅助数组
        for (int i = 0; i < fd_num_max; i++)
        {
            _event_fds[i].fd = defaultfd;
            _event_fds[i].events = non_event;
            _event_fds[i].revents = non_event; // 可不设，这个由OS设置
        }
    }
    ~PollServer()
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
            if (_event_fds[pos].fd != defaultfd)
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
            _event_fds[pos].fd = sock;
            _event_fds[pos].events = POLLIN;
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
            _event_fds[pos].fd = defaultfd; // 本质是从poll中移除
        }
        else
        {
            lg(Warning, "recv error, fd is : %d", fd);
            close(fd);
            _event_fds[pos].fd = defaultfd; // 本质是从poll中移除
        }
    }

    void Dispatcher()
    {
        for (int i = 0; i < fd_num_max; i++)
        {
            int fd = _event_fds[i].fd;
            if (fd == defaultfd)
                continue;

            if (_event_fds[i].revents & POLLIN)
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
        _event_fds[0].fd = _listensock.Fd();
        _event_fds[0].events = POLLIN; // 这里固定数组第一个位置，监听文件描述符
        int timeout = 3000; // 3s
        for (;;)
        {
            int n = poll(_event_fds, fd_num_max, timeout);
            switch (n)
            {
            case 0:
                cout << "time out... " << endl;
                break;
            case -1:
                cerr << "poll error" << endl;
            default:
                // 有事情就绪了，TODO
                cout << "get new link!!!!" << endl;
                Dispatcher();
                break;
            }
        }
    }

    void PrintFd()
    {
        cout << "online fd list: " << endl;
        for (int i = 0; i < fd_num_max; i++)
        {
            if (_event_fds[i].fd == defaultfd)
                continue;
            cout << _event_fds[i].fd << ' ';
        }
        cout << endl;
    }

private:
    Sock _listensock;
    uint16_t _port;
    struct pollfd _event_fds[fd_num_max];
    // int rfd_array[fd_num_max];
};