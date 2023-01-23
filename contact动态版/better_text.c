#define _CRT_SECURE_NO_WARNINGS
#include"better_contact.h"
int main()
{
	Init_contact(&con);
	int input;
	do
	{
		meun();
		printf("«Î ‰»Î ˝◊÷;>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add_contact(&con);
			break;
		case 2:
			Del_contact(&con);
			break;
		case 3:
			Search_contact(&con);
			break;
		case 4:
			Modify_contact(&con);
			break;
		case 5:
			Show_contact(&con);
			break;
		case 6:
			Clean__contact(&con);
			break;
		case 7:
			Sort_contact(&con);
		case 0:
			Save_contact(&con);
			Destory_contact(&con);
		default:
			printf(" ‰»Î¥ÌŒÛ");
			break;
		}
	} while (input);
	return 0;
}