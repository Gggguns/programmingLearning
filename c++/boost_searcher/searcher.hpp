#pragma once

#include"index.hpp"
#include"util.hpp"
#include<algorithm>
#include<jsoncpp/json/json.h>

namespace ns_searcher{
  class Searcher{
    private:
      ns_index::Index* index;  //供操作系统查找的索引

    public:
      Searcher(){}
      ~Searcher(){}
    public:
      void InitSearch(const std::string& input){
        //1.获取或者创建index对象
        index=ns_index::Index::GetInstance();
        std::cout<<"获取index单例成功..."<<std::endl;
        //2.根据index对象建立索引
        index->BuildIndex(input);
        std::cout<<"建立正排和倒排索引成功..."<<std::endl;
      }

      //query:  搜索关键字
      //json_string:  返回给用户浏览器的搜索结果
      void Search(const std::string& query,std::string* json_string){
        //1.[分词]: 对我们的query按照seacher的要求进行分词
        std::vector<std::string> words;
        ns_util::JiebaUtil::CutString(query,&words);
        //2.[触发]: 就是根据分词的各个"词",进行index查找
        ns_index::InvertedList inverted_list_all;//内部InvertedElem
        for(std::string word: words){
          boost::to_lower(word);
          ns_index::InvertedList* inverted_list=index->GetInvertedIndex(word);
          if(nullptr==inverted_list){
            continue;
          }
          inverted_list_all.insert(inverted_list_all.end(),inverted_list->begin(),inverted_list->end());
        }
        //3.[合并排序]: 汇总结果，按照相关性(weight)降序排序
        std::sort(inverted_list_all.begin(),inverted_list_all.end(),\
            [](const ns_index::InvertedElem& e1,const ns_index::InvertedElem& e2){
              return e1.weight>e2.weight;
            });
        //4.[构建]: 根据查找出来的结果，构建json_string串--jsoncpp完成序列化&&反序列化
        Json::Value root;
        for(auto& item:inverted_list_all){
          ns_index::DocInfo* doc=index->GetForwardIndex(item.doc_id);
          if(nullptr==doc){
            continue;
          }

          Json::Value elem;
          elem["title"]=doc->title;
          elem["desc"]=GetDesc(doc->content,item.word);  //content是文档去标签后的结果，但不是我们想要的，我们只需要一部分
          elem["url"]=doc->url;
          
          //for debug 
          elem["doc_id"]=(int)doc->doc_id;
          elem["weight"]=item.weight;
          root.append(elem);
        }

        Json::StyledWriter writer;
        *json_string=writer.write(root);

      }
      std::string GetDesc(const std::string& html_content,const std::string& word){
        const std::size_t prev_step=50;
        const std::size_t next_step=100;
        //1.找到首次出现
        auto iter=std::search(html_content.begin(),html_content.end(),word.begin(),word.end(),[](int x,int y){
            return std::tolower(x)==std::tolower(y);
            });
        if(iter==html_content.end()){
          return "None.";
        }
        std::size_t pos=std::distance(html_content.begin(),iter);
        
        //2.获取start end
        std::size_t start=0;
        std::size_t end=html_content.size()-1;
        //如果之前有50个字符，更新start
        if(pos>start+prev_step)start=pos-prev_step;
        //如果之后有100个字符，更新end
        if(pos+next_step<end)end=pos+next_step;
        //3.截取字串，return
        if(start>=end)return "None.";
        std::string desc= html_content.substr(start,end-start+1);
        desc+="...";
        return desc;

      }
  };

}











