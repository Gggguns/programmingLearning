#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<boost/filesystem.hpp>
#include"util.hpp"

//是一个目录，下面放的是所有的html网页
const std::string src_path="data/input";
const std::string output="data/raw_html/raw.txt";

typedef struct DocInfo{
  std::string title;   //文件的标题
  std::string content; //文件的内容
  std::string url;     //该文件在官方网站的网址
}DocInfo_t;

bool EnumFiles(const std::string& src_path,std::vector<std::string>* files_list);
bool ParseHtml(const std::vector<std::string>& files_list,std::vector<DocInfo_t>* results);
bool SaveHtml(const std::vector<DocInfo_t>& results,const std::string& output);


int main(){
  std::vector<std::string> files_list;
  //第一步:递归式的把每一个html文件名带带路径，保存到files_list中，方便后期进行一个一个的文件读取
  if(!EnumFiles(src_path,&files_list)){
    std::cerr<<"enum file name error\n";
    return 1;
  }
  std::vector<DocInfo_t> results;
  //第二步:按照files_list读取每个文件的内容，并进行解析
  if(!ParseHtml(files_list,&results)){
    std::cerr<<"parse html error\n";
    return 2;
  }
  //第三步:把解析完毕的各个文件内容，写入到output,按照\3作为每个文档的分隔符
  if(!SaveHtml(results,output)){
    std::cerr<<"save html error\n";
    return 3;
  }
  return 0;
}

//枚举路径名
bool EnumFiles(const std::string& src_path,std::vector<std::string>* files_list){
  namespace fs=boost::filesystem;
  fs::path root_path(src_path);
  //判断路径是否存在，不存在,就没必要继续了
  if(!fs::exists(root_path)){
    std::cerr<<src_path<<" not exists"<<std::endl;
    return false;
  }
  //定义一个空迭代器，用来进行判断递归结束
  fs::recursive_directory_iterator end; 
  for(fs::recursive_directory_iterator iter(root_path);iter!=end;iter++){
    //判断文件是不是普通文件，html都是普通文件
    if(!fs::is_regular_file(*iter)){
      continue;
    }
    //判断路径名的后缀是不是html
    if(iter->path().extension()!=".html"){
      continue;
    }
    //输出符合要求的路径名
    //std::cout<<"debug: "<<iter->path().string()<<std::endl;
    //当前路径一定是一个合法的，以.html结束的普通网页文件
    files_list->push_back(iter->path().string());//将所有带路径的html保存在files_list中
  }
  return true;
}

static bool ParseTitle(const std::string& file,std::string* title){
  std::size_t begin=file.find("<title>");
  if(begin==std::string::npos){
    return false;
  }
  std::size_t end=file.find("</title>");
  if(end==std::string::npos){
    return false;
  }
  begin+=std::string("<title>").size();
  if(begin>end){
    return false;
  }
  *title=file.substr(begin,end-begin);
  return true;
}
static bool ParseContent(const std::string& file,std::string* content){
  //去标签，基于一个简单的状态机
  enum status{
    LABEL,
    CONTENT
  };
  enum status s=LABEL;
  for(char c:file){
    switch(s){
      case LABEL:
        if(c=='>')s=CONTENT;
        break;
      case CONTENT:
        if(c=='<')s=LABEL;
        else{
          //我们不保留原文件中的\n，因为我们想用\n作为html解析之后文档的分割符
          if(c=='\n')c=' ';
          content->push_back(c);
        }
        break;
      default:
        break;
    }
  }
  return true;
}
static bool ParseUrl(const std::string& file_path,std::string* url){
  std::string url_head="https://www.boost.org/doc/libs/1_85_0/doc/html";
  std::string url_tail=file_path.substr(src_path.size());

  *url=url_head+url_tail;
  return true;
}

//for debug
static void ShowDoc(const DocInfo_t& doc){
  std::cout<<"title: "<<doc.title<<std::endl;
  std::cout<<"content: "<<doc.content<<std::endl;
  std::cout<<"url: "<<doc.url<<std::endl;
}

//解析html文件
bool ParseHtml(const std::vector<std::string>& files_list,std::vector<DocInfo_t>* results){
  for(const std::string& file:files_list){
    //1.读取文件，ReadFile
    std::string result;
    if(!ns_util::FileUtil::ReadFile(file,&result)){
      continue;
    }
    //2.解析指定文件，提取它的title
    DocInfo doc;
    if(!ParseTitle(result,&doc.title)){
      continue;
    }
    //3.解析指定文件，提取它的content
    if(!ParseContent(result,&doc.content)){
      continue;
    }
    //4.解析指定文件路径，构建它的url
    if(!ParseUrl(file,&doc.url)){
      continue;
    }
    //done,一定完成了解析任务，当前文档的相关结果都保存在了doc中
    results->push_back(std::move(doc));//bug:todo:本质会发生拷贝，效率可能比较低
    
    //for debug
    //ShowDoc(doc);
    //break;
  }
  return true;
}
bool SaveHtml(const std::vector<DocInfo_t>& results,const std::string& output){
#define SEP '\3'
  //按照二进制方式写入
  std::ofstream out(output,std::ios::out | std::ios::binary);
  //判断文件是否打开
  if(!out.is_open()){
    std::cerr<<"open "<<output<<" failed"<<std::endl;
  }
  //进行文件内容写入,文档内以/3作为分隔符，文档间以\n作为分割符
  for(const DocInfo_t&item:results){
    std::string out_string;
    out_string+=item.title;
    out_string+=SEP;
    out_string+=item.content;
    out_string+=SEP;
    out_string+=item.url;
    out_string+='\n';
    out.write(out_string.c_str(),out_string.size());
  }
  return true;
}

























































