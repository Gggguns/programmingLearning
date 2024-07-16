#include"cpp-httplib/httplib.h"
#include"searcher.hpp"

const std::string input="./data/raw_html/raw.txt";
const std::string root_path="./wwwroot";

int main()
{

  httplib::Server svr;
  ns_searcher::Searcher search;

  search.InitSearch(input);
  svr.set_base_dir(root_path.c_str());
  svr.Get("/s", [&search](const httplib::Request &req, httplib::Response &rsp){
    //rsp.set_content("你好,世界!", "text/plain; charset=utf-8");
      if(!req.has_param("word")){
        rsp.set_content("必须要有搜索关键字！","text/plain; charset=utf-8");
      }
      else{
        std::string word=req.get_param_value("word");
        std::cout<<"用户在搜索："<<word<<std::endl;
        std::string json_string;
        search.Search(word,&json_string);
        rsp.set_content(json_string,"application/json");
      }
  });
  svr.listen("0.0.0.0", 8081);
  return 0;
}
