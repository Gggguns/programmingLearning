#define _CRT_SECURE_NO_WARNINGS
#include"better_contact.h"
//菜单
void menu(void)
{
	printf("***************************************\n");
	printf("***************************************\n");
	printf("***************************************\n");
	printf("***************************************\n");
	printf("***************************************\n");
	printf("***************************************\n");
}
//初始化通讯录函数
void Init_contact(Contact* con);
//检查容量函数
void Check_capacity(Contact* con);
//增加联系人函数
void Add_contact(Contact* con);
//以姓名查找函数
void Find_name(Contact* con)
;
//删除联系人函数
void Del_contact(Contact* con);

//搜索联系人函数
void Searcch_contact(Contact* con);

//更改联系人的信息函数
void Modify_contact(Contact* con);

//显示所有联系人函数
void Show_contact(Contact* con);

//清理所有联系人函数
void Clean_contact(Contact* con);


//排序联系人函数
void Sort_contact(Contact* con);


//保存所有联系人信息函数
void Save_contact(Contact* con);


//摧毁所所有联系人信息函数
void Destory(Contact* con);
{