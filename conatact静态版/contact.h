#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define exit 0
#define add  1
#define del 2
#define search 3
#define modify 4
#define show 5
#define MAX_name 10
#define MAX_addr 20
#define MAX_data 100
void menu();
void Initcontact(struct contact2 *con);
struct contact1
{
	char name[MAX_name];
	int tele;
	int age;
	char addr[MAX_addr];
};
typedef struct contact2
{
	struct contact1 data[MAX_data];
	int sz;
}con2;
con2 con;
//以姓名查找
int Find_name(con2 *con, char name[]);
//增加联系人
void Add(con2 *con);
//显示联系人
void Show(con2 *con);
//删除联系人
void Del(con2 *con);
//搜索联系人
void Search(con2 *con);
//修改联系人
void Mondif(con2 *con);