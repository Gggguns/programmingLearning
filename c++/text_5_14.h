#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//参数类型不同
int add(int x , int y );

double add(double x , double y );

//参数个数不同
int Dul(int x, int y , int z );

int Dul(int x, int y);

//参数类型顺序不同
double add(double x, int y);

double add(int x, double y);