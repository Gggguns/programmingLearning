#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#define Max_name 10
#define Max_addr 50
#define Add 1
#define Max_sex 5
#define Max_tele 20
#define Max_age 5
typedef struct Peoinf
{
	char name[Max_name];
	char sex[Max_sex];
	char tele[Max_tele];
	char age[Max_age];
	char addr[Max_addr];
}Peoinf;
typedef struct Contact
{
	struct Peoinf* data;
	int sz;
	int Capacity;
}Contact;

//菜单 
void menu();

//下载通讯录
void load_contact(Contact* con);

//初始化通讯录
void Init_contact(Contact* con);

//检查容量
int Check_capacity(Contact* con);

//增加联系人
void Add_contact(Contact* con);

//以姓名查找
int Find_name(Contact* con);

//删除联系人
void Del_contact(Contact* con);

//搜索联系人
void Search_contact(Contact* con);

//更改联系人的信息
void Modify_contact(Contact* con);

//显示所有联系人
void Show_contact(Contact* con);

//清理所有联系人
void Clean_contact(Contact* con);

//排序联系人
void Sort_contact(Contact* con);

//以姓名排序
int cmp1(const void* e1, const void* e2);

//保存联系人信息
void Save_contact(Contact* con);

//摧毁所所有联系人信息
void Destory_contact(Contact* con);

