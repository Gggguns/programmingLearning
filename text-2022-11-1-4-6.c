#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int sed, h, m, s;
    scanf("%d", &sed);
    if (sed < 60)
    {
        h = 0;
        m = 0;
        s = sed;
    }
    else if (sed < 3600)
    { 
        s = sed % 60;
        m = sed / 60;
        h = 0;
    }
    else
    {
        s = sed % 60;
        m = (sed / 60) % 60;
        h = sed / 3600;
    }
    printf("%d %d %d", h, m, s);
    return 0;
}