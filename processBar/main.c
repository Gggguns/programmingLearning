#include"processBar.h"
int main()
{
  int cout=10;
  while(cout>=0)
  {
    printf("%-2d\r",cout);
    fflush(stdout);
    sleep(1);
    cout--;
  }
  printf("\n");
  return 0;
}
