#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("**********************************************\n");
	printf("*******     0.exit        1.add    ***********\n");
	printf("*******     2.del         3.search ***********\n");
	printf("*******     4.modify      5.show   ***********\n");
	printf("*******     6.                     ***********\n");
	printf("**********************************************\n");
}
void Initcontact(struct contact2* con)
{
	assert(con);
	con->sz = 0;
	memset(con->data, '0', sizeof(con->data));
}
void Add(con2 *con)
{
	assert(con);
	if (con->sz > 100)
	{
		printf("联系人已满，无法增加\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", con->data[con->sz].name);
	printf("请输入电话:>");
	scanf("%d", &con->data[con->sz].tele);
	printf("请输入年龄:>");
	scanf("%d", &con->data[con->sz].age);
	printf("请输入地址:>");
	scanf("%s", con->data[con->sz].addr);
	con->sz++;
}
void Show(con2 *con)
{
	assert(con);
	int i = 0;
	printf("%-10s\t%-15s\t%-4s\t%-10s\n", "名字", "电话", "年龄", "地址");//双引号用于字符串，单引号用于单个字符
	for(i=0;i<con->sz;i++)
	{
		printf("%-10s\t%-15d\t%-4d\t%-10s\n", con->data[i].name, con->data[i].tele, con->data[i].age, con->data[i].addr);
	}
}
void Del(con2 *con)
{
	assert(con);
	printf("请输入名字:>");
	char name[10];
	scanf("%s", name);
	int ret=Find_name(con,name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
		return;
	}
	int i = 0;
	for (i = ret;i < con->sz;i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->sz--;
}
int Find_name(con2 *con,char name[])
{
	assert(con);
	int i=0;
	for (i = 0;i < con->sz;i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
			return i;
	}
	return -1;
}
void Search(con2 *con)
{
	assert(con);
	printf("请输入名字:>");
	char name[10];
	scanf("%s", name);
	int ret = Find_name(con, name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
		return;
	}
	printf("%-10s\t%-15s\t%-4s\t%-10s\n", "名字", "电话", "年龄", "地址");//双引号用于字符串，单引号用于单个字符
	printf("%-10s\t%-15d\t%-4d\t%-10s\n", con->data[ret].name, con->data[ret].tele, con->data[ret].age, con->data[ret].addr);
}
void Mondif(con2* con)
{
	assert(con);
	printf("请输入需要修信息的人的名字:>");
	char name[10];
	scanf("%s", name);
	int ret = Find_name(con, name);
	if (ret == -1)
	{
		printf("不存在该联系人\n");
		return;
	}
	printf("请输入更改的名字:>");
	scanf("%s", con->data[ret].name);
	printf("请输入更改的电话:>");
	scanf("%d", &con->data[ret].tele);
	printf("请输入更改的年龄:>");
	scanf("%d", &con->data[ret].age);
	printf("请输入更改的地址:>");
	scanf("%s", con->data[ret].addr);
}