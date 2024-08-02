#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  const char *fstr = "hello fwrite\n";
  const char *str = "hello write\n";

  printf("hello printf\n");             //stdout -> 1
  fprintf(stdout, "hello fprintf\n");   //stdout -> 1
  fwrite(fstr, strlen(fstr), 1, stdout);//stdout -> 1
  write(1, str, strlen(str));
  close(1);

  //fork();

  return 0;
}
