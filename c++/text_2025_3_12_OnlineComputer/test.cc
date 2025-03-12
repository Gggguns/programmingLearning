#include <iostream>
#include <jsoncpp/json/json.h>

// {a: 120, b:"123"}
int main()
{
    Json::Value part1;
    part1["haha"] = "haha";
    part1["hehe"] = "hehe";
    // Json中有一个万能对象叫Value，可以接受任意类型
    Json::Value root;
    // 增加数据的方式是 root[key] = value，value都可以是任意类型
    root["x"] = 100;
    root["y"] = 200;
    root["op"] = '+';
    root["desc"] = "this is a + oper";
    root["test"] = part1;

    // writer对象，有StyledWriter和FastWriter两种
    // Json::FastWriter w;
    Json::StyledWriter w;
    std::string res = w.write(root);
    std::cout << res << std::endl;

    Json::Value v;
    Json::Reader r;
    r.parse(res, v);

    int x = v["x"].asInt();
    int y = v["y"].asInt();
    // 字符的本质就是一个整数
    char op = v["op"].asInt();
    std::string desc = v["desc"].asString();
    Json::Value temp = v["test"];

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << op << std::endl;
    std::cout << desc << std::endl;
    std::cout << temp << std::endl;
    return 0;
}