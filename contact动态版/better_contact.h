#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define Max_name 10
#define Max_addr 50
#define Add 1
struct Peoinf
{
	char name[Max_name];
	char sex;
	int tele;
	int age;
	char addr[Max_addr];
};
typedef struct Contact
{
	struct Peoinf* data;
	int sz;
	int Capacity;
}Contact;
Contact con;
//菜单 
void menu()
//初始化通讯录
void Init_contact(Contact* con);
//检查容量
void Check_capacity(Contact* con);
//增加联系人
void Add_contact(Contact* con);
//以姓名查找
void Find_name(Contact* con);
//删除联系人
void Del_contact(Contact* con);
//搜索联系人
void Searcch_contact(Contact* con);
//更改联系人的信息
void Modify_contact(Contact* con);
//显示所有联系人
void Show_contact(Contact* con);
//清理所有联系人
void Clean_contact(Contact* con);
//排序联系人
void Sort_contact(Contact* con);
//保存联系人信息
void Save_contact(Contact* con);
//摧毁所所有联系人信息
void Destory(Contact* con);

