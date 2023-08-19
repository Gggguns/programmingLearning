#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
class Teacher:public Person
{
	std::string posts;
};
class Student:public Person
{
	std::string Class;
};
class Person
{
	std::string name;
	std::string number;
	std::string address;
};
int main()
{
	return 0;
}