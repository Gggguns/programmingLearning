#include <iostream>
using namespace std;


int main(int argc, char *argv[],char *env[]){
  cout<<argv[0]<<" begin running\n";
  cout<<"这是命令行参数: \n";
  int i=0;
  for(i=0;i<argc;i++){
    cout<<i<<" : "<<argv[i]<<endl;
  }
  cout<<"这是环境变量信息: \n";
  for(i=0;env[i];i++){
    cout<<i<<" : "<<env[i]<<endl;
  }
  cout<<argv[0]<<" stop running\n";
  //cout<<"Hello Linux\n"<<endl;
  //cout<<"Hello Linux\n"<<endl;
  //cout<<"Hello Linux\n"<<endl;
  //cout<<"Hello Linux\n"<<endl;
  //cout<<"Hello Linux\n"<<endl;
  //cout<<"Hello Linux\n"<<endl;
  return 0;
}
