#define _CRT_SECURE_NO_WARNINGS
#include"better_contact.h"
//菜单
void menu(void)
{
	printf("*************************************\n");
	printf("******   1.Add      2.Del     *******\n");
	printf("******   3.Search   4.Modify  *******\n");
	printf("******   5.Show     6.Clean   *******\n");
	printf("******   7.Sort               *******\n");
	printf("*************************************\n");
	return;
}

//下载通讯录
void load_contact(Contact* con)
{
	FILE* pf = fopen("cc.txt", "rb");
	if (pf == NULL)
	{
		perror("load_contact");
		return;
	}
	else
	{
		int i = 0;
		Peoinf tmp = { 0 };
		while (fread(&tmp, sizeof(Peoinf), 1, pf))
		{
			Check_capacity(con);
			con->data[i] = tmp;
			i++;
			con->sz++;
		}
		fclose(pf);
		pf = NULL;
	}
}

//初始化通讯录函数
void Init_contact(Contact* con)
{
	assert(con);
	con->sz = 0;
	Peoinf* ptr = calloc(3, sizeof(struct Peoinf));
	if (NULL == ptr)
	{
		perror("Init_contact calloc");
		return;
	}
	else
	{
		con->data = ptr;
		con->Capacity = 3;
		load_contact(con);
		return;
	}
}
//检查容量函数
int Check_capacity(Contact* con)
{
	assert(con);
	if (con->sz == con->Capacity)
	{
		Peoinf* prt = realloc(con->data, (con->Capacity + 2) * sizeof(Peoinf));
		if (NULL == prt)
		{
			perror("Check_capacipy realloc");
			return 0;
		}
		else
		{
			con->data = prt;
			con->Capacity = con->Capacity + 2;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;
}
//增加联系人函数
void Add_contact(Contact* con)
{
	assert(con);
	int ret = Check_capacity(con);
	if (0 == ret)
	{
		printf("通讯录容量已满，增容失败，无法继续增加联系人\n");
		return;
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", con->data[con->sz].name);
		printf("请输入性别:>");
		scanf("%s", con->data[con->sz].sex);
		printf("请输入年龄:>");
		scanf("%s", con->data[con->sz].age);
		printf("请输入电话:>");
		scanf("%s", con->data[con->sz].tele);
		printf("请输入地址:>");
		scanf("%s", con->data[con->sz].addr);
		con->sz++;
		return;
	}
}
//以姓名查找函数
int Find_name(Contact* con)
{
	assert(con);
	char name[Max_name];
	scanf("%s", name);
	for (int i = 0;i < con->sz; i++)
	{
		if (strcmp((con->data[i].name), name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人函数
void Del_contact(Contact* con)
{
	assert(con);
	printf("请输入要删除联系人的姓名:>");
	int ret = Find_name(con);
	if (-1 == ret)
	{
		printf("该联系人不存在\n");
		return;
	}
	else
	{
		for (int i = ret;i < con->sz - 1;i++)
		{
			con->data[i] = con->data[i + 1];
		}
		con->sz--;
		return;
	}
}

//搜索联系人函数
void Search_contact(Contact* con)
{
	assert(con);
	printf("请输入要查找联系人的姓名:>");
	int ret = Find_name(con);
	if (-1 == ret)
	{
		printf("该联系人不存在\n");
		return;
	}
	else
	{
		printf("%-10s\t%-1s\t%-15s\t%-4s\t%-10s\n", " 姓名", "性别", "电话", "年龄", "地址");
		printf("%-10s\t%-1s\t%-15s\t%-4s\t%-10s\n", con->data[ret].name, con->data[ret].sex, con->data[ret].tele, con->data[ret].age, con->data[ret].addr);
		return;
	}
}

//更改联系人的信息函数
void Modify_contact(Contact* con)
{
	assert(con);
	printf("请输入要更改信息联系人的姓名:>");
	int ret = Find_name(con);
	if (-1 == ret)
	{
		printf("该联系人不存在\n");
		return;
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", con->data[ret].name);
		printf("请输入性别:>");
		scanf("%s", con->data[ret].sex);
		printf("请输入电话:>");
		scanf("%s", con->data[ret].tele);
		printf("请输入年龄:>");
		scanf("%s", con->data[ret].age);
		printf("请输入地址:>");
		scanf("%s", con->data[ret].addr);
		return;
	}
}

//显示所有联系人函数
void Show_contact(Contact* con)
{
	printf("%-10s\t%-1s\t%-15s\t%-4s\t%-10s\n", " 姓名", "性别", "电话", "年龄", "地址");
	for (int i = 0;i < con->sz;i++)
	{
		printf("%-10s\t%-1s\t%-15s\t%-4s\t%-10s\n", con->data[i].name, con->data[i].sex, con->data[i].tele, con->data[i].age, con->data[i].addr);
	}
	return;
}

//清理所有联系人函数
void Clean_contact(Contact* con)
{
	assert(con);
	free(con->data);
	con->data = NULL;
	Init_contact(con);
	return;
}

//以姓名排序
int cmp1(const void* e1, const void* e2)
{
	return strcmp(((Peoinf*)e1)->name, ((Peoinf*)e2)->name);
}

//排序联系人函数
void Sort_contact(Contact* con)
{
	assert(con);
	qsort(con->data, con->sz, sizeof(Peoinf), cmp1);
	return;
}


//保存所有联系人信息函数
void Save_contact(Contact* con)
{
	FILE* pf = fopen("cc.txt", "wb");
	if (NULL == pf)
	{
		perror("Save_contact");
		return;
	}
	else
	{
		int i = 0;
		for (i = 0;i < con->sz;i++)
		{
			fwrite(con->data + i, sizeof(Peoinf), 1, pf);
		}
		fclose(pf);
		pf = NULL;
		printf("保存成功\n");
	}
}


//摧毁所所有联系人信息函数
void Destory_contact(Contact* con)
{
	assert(con);
	free(con->data);
	con->data = NULL;
	return;
}
