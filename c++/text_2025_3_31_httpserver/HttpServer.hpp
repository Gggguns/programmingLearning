#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <pthread.h>
#include "Socket.hpp"
#include "Log.hpp"

const std::string wwwroot = "./wwwroot";
const std::string sep = "\r\n";
const std::string homepage = "index.html";

static const uint16_t defaultport = 8080;

class HttpServer;

struct ThreadData
{
public:
    ThreadData(int fd, HttpServer *s): sockfd(fd), svr(s) 
    {}
public:
    int sockfd;
    HttpServer *svr;
};

class HttpRequest
{
public:
    // 切分请求
    void Deserialize(std::string req)
    {
        while(true)
        {
            size_t pos = req.find(sep);
            if(pos == std::string::npos) break;
            std::string temp = req.substr(0, pos);
            if(temp.empty()) break;
            req_header.push_back(temp);
            req.erase(0, pos+sep.size());
        }
        text = req;
    }
    //解析请求行
    void Parse()
    {
        //stringstream对象会以空格作为分隔符，分隔字符串
        std::stringstream ss(req_header[0]);
        ss >> method >> url >> http_version;

        file_path = wwwroot; // ./wwwroot
        if(url == "/" || url == "index.html")
        {
            file_path += "/";
            file_path += homepage; // ./wwwroot/index.html
        }
        else file_path += url;

        // 确认文件后缀
        size_t pos = file_path.rfind(".");
        if(pos == std::string::npos) suffix = ".html";
        else suffix = file_path.substr(pos);
    }
    // 打印
    void DebugPrint()
    {
        std::cout << "-------------------------------------" << std::endl;
        for(auto& line : req_header)
        {
            std::cout << line << "\n\n";
        }
        std::cout << "method: " << method << std::endl;
        std::cout << "url: " << url << std::endl;
        std::cout << "http_sersion: " << http_version << std::endl;
        std::cout << "file_path: " << file_path << std::endl;
        std::cout << text << std::endl;
    }
public:
    std::vector<std::string> req_header;
    std::string text;

    // 解析之后的结果
    std::string method;
    std::string url;
    std::string http_version;
    std::string file_path;

    std::string suffix;
};

class HttpServer
{
public:
    HttpServer(uint16_t port = defaultport):port_(port)
    {
        content_type.insert({".html", "text/html"});
        content_type.insert({".png", "image/png"});
    }
    bool Start()
    {
        listensock_.Socket();
        listensock_.Bind(port_);
        listensock_.Listen();
        for(;;)
        {
            std::string clientip;
            uint16_t clientport;
            int sockfd = listensock_.Accept(&clientip, &clientport);
            lg(Info, "get a new connect, sockfd: %d", sockfd);
            pthread_t tid;
            ThreadData *td = new ThreadData(sockfd, this);
            td->sockfd = sockfd;
            pthread_create(&tid, nullptr, ThreadRun, td);
        }
    }
    static std::string ReadHtmlContent(const std::string &htmlpath)
    {
        std::ifstream in(htmlpath, std::ios::binary);
        // if(!in.is_open()) return "404";
        if(!in.is_open()) return "";
        in.seekg(0, std::ios_base::end);
        auto len = in.tellg();
        in.seekg(0, std::ios_base::beg);

        std::string content;
        content.resize(len);
        in.read((char*)content.c_str(), content.size());
        // std::string content;
        // std::string line;
        // while(getline(in, line))
        // {
        //     content += line;
        // }
        in.close();
        return content;
    }
    // 后缀对应的文件类型
    std::string SuffixToDesc(const std::string &suffix)
    {
        auto iter = content_type.find(suffix);
        if(iter == content_type.end()) return content_type[".html"];
        else return content_type[suffix];
    }
    void HandlerHttp(int sockfd)
    {
        char buffer[10240];
        ssize_t n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
        if(n > 0)
        {
            buffer[n] = 0;
            std::cout << buffer; // 假设读到的就是一个完整的，独立的http请求
            HttpRequest req;
            req.Deserialize(buffer);
            req.Parse();
            // req.DebugPrint();

            // 返回响应的过程
            std::string text = ReadHtmlContent(req.file_path);
            bool ok = true;
            if(text.empty())
            {
                ok = false;
                std::string err_html = wwwroot;
                err_html += "/";
                err_html += "err.html";
                text = ReadHtmlContent(err_html);
            }

            std::string response_line = "HTTP/1.0 200 OK\r\n";
            if(ok)
                response_line = "HTTP/1.0 200 OK\r\n";
            else 
                response_line = "HTTP/1.0 404 Not Found\r\n";
            // response_line = "HTTP/1.0 302 Found\r\n";
            std::string response_header = "Content-Length: ";
            response_header += std::to_string(text.size()); // Content-Length: 11
            response_header += "\r\n";
            response_header += "Content-Type: ";
            response_header += SuffixToDesc(req.suffix);
            response_header += "\r\n";
            response_header += "Set-Cookie: name=haha&&passwd=djasldija";
            response_header += "\r\n";
            // response_header += "Location: https://www.qq.com/\r\n";
            std::string blank_line = "\r\n";

            std::string response = response_line;
            response += response_header;
            response += blank_line;
            response += text;
            
            send(sockfd, response.c_str(), response.size(), 0);
        }
        close(sockfd);
    }
    static void *ThreadRun(void *args)
    {
        ThreadData *td = static_cast<ThreadData*>(args);
        pthread_detach(pthread_self());
        td->svr->HandlerHttp(td->sockfd);
        delete td;
        return nullptr;
    }
    ~HttpServer()
    {}
private:
    Sock listensock_;
    uint16_t port_;
    std::unordered_map<std::string, std::string> content_type;
};