#define _CRT_SECURE_NO_WARNINGS
#include "path.hpp"
#include "util.hpp"

int main() {
    //输出格式控制
    SetConsoleOutputCP(CP_UTF8);
    std::string curl_result;
    //Path::addressTranslationLatitudeAndLongitude();
    ns_path::Path::getGuidance(&curl_result);
    std::cout << curl_result << std::endl;
    ns_path::Path::extractInstrctionFromJson(curl_result);
   
    return 0;
}
