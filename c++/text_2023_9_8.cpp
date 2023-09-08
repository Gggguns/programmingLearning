#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#pragma pack(12)
using namespace std;


struct A
{
private:
	int a;
	char c;
	double d;
	
};
struct B
{
private:
	int b;
	char ch;
	char d;
	A a;
	//char c;
};


int main()
{
	A a;
	B b;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	return 0;
}