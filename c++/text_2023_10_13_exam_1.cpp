#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class LCA {
public:
    int getLCA(int a, int b) {
        while (a != b)
        {
            if (a > b)
            {
                a /= 2;
            }
            else
            {
                b /= 2;
            }
        }
        return a;

    }
};
int main()
{
	return 0;
}