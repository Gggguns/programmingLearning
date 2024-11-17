#pragma once
#include "util.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <map>
#include <curl/curl.h>
using json = nlohmann::json;
// 编译时请使用-lcurl链接libcurl库，例如：g++ test.cpp -o test -lcurl

// 此处填写您在控制台-应用管理-创建应用后获取的AK
std::string ak = "0AFgwYGcQKt4UUcwxtPqu1YjBfD7gbda";

namespace ns_path
{
    class Path
    {
    public:
        // @brief curl发送http请求调用的回调函数，回调函数中对返回的json格式的body进行了解析，解析结果储存在result中
        // @param 参数定义见libcurl库文档
        // @return 返回值定义见libcurl库文档
        static size_t callback(void* ptr, size_t size, size_t nmemb, void* stream) {
            // 获取到的http body存放在ptr中，先将其转换为string格式
            std::string s((char*)ptr, size * nmemb);
            std::string* result = static_cast<std::string*>(stream);
            *result += s;
            return size * nmemb;
        }

        //地址转经纬度
        static void addressTranslationLatitudeAndLongitude() {
            // 接口地址
            std::string uri = "/geocoding/v3";

            // 服务地址
            // libcurl默认是不支持SSL的, 如果需要支持https，请在libcurl的编译选项中设置
            std::string host = "http://api.map.baidu.com";

            // 设置请求参数
            std::map<std::string, std::string> params;
            params["address"] = "北京市海淀区上地十街10号";
            params["output"] = "json";
            params["ak"] = ak;
            params["callback"] = "showLocation";

            std::string curl_result;
            //发送请求
            sendRequest(uri, params, &curl_result);
            std::cout << curl_result << std::endl;
            //裁剪字符串
            size_t start = curl_result.find('(');
            size_t end = curl_result.find(')');
            std::string json_str = curl_result.substr(start + 1, end - start - 1);
            //解析JSON字符串
            json j = json::parse(json_str);

            //经纬度
            double lng = j["result"]["location"]["lng"];
            double lat = j["result"]["location"]["lat"];
            std::cout << "lng: " << lng << std::endl;
            std::cout << "lat: " << lat << std::endl;

        }
        //获取指引
        static void getGuidance(std::string* curl_result) {
            //接口地址
            std::string uri = "/directionlite/v1/walking";
            // 设置请求参数
            std::map<std::string, std::string> params;
            params["origin"] = "40.01116,116.339303";
            params["destination"] = "39.936404,116.452562";
            params["output"] = "json";
            params["ak"] = ak;
            //发送请求
            sendRequest(uri, params, curl_result);
        }
        //向API发送请求
        static void sendRequest(const std::string& uri, const std::map<std::string, std::string>& params, std::string* curl_result)
        {

            // 服务地址
            // libcurl默认是不支持SSL的, 如果需要支持https，请在libcurl的编译选项中设置
            std::string host = "http://api.map.baidu.com";

            std::string query_str = "";
            for (auto& i : params) {
                query_str += "&" + i.first + "=" + i.second;
            }
            query_str = uri + "?" + query_str.substr(1);

            // 发送请求
            CURL* curl;
            CURLcode result_code;
            int error_code = 0;
            curl = curl_easy_init();
            if (curl) {
                //std::string curl_result;
                std::string url = host + query_str;

                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
                curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, curl_result);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
                result_code = curl_easy_perform(curl);
                if (result_code != CURLE_OK) {
                    std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(result_code) << std::endl;
                    //报错
                    return;
                }
                curl_easy_cleanup(curl);
            }
        }

        //从Json中提出指引信息
        static void extractInstrctionFromJson(const std::string& json_str)
        {
            // 将 JSON 字符串解析为 json 对象
            json data = json::parse(json_str);

            // 检查 "routes" 是否存在
            if (data.contains("result") && data["result"].contains("routes")) {
                // 遍历 routes 中的每个元素
                for (const auto& route : data["result"]["routes"]) {
                    if (route.contains("steps")) {
                        // 遍历 steps 中的每个元素
                        for (const auto& step : route["steps"]) {
                            // 检查是否包含 instruction 字段
                            if (step.contains("instruction")) {
                                // 输出 instruction 信息
                                //std::cout << "Instruction: " << step["instruction"] << std::endl;
                                std::string instruction = step["instruction"];
                                ns_util::JsonUtil::removeLabel(instruction);
                                std::cout << instruction << std::endl;
                            }
                        }
                    }
                }
            }
            else {
                std::cout << "No routes or steps found in the JSON data." << std::endl;
            }
        }
    };
}