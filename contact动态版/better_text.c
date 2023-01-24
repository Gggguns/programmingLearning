#define _CRT_SECURE_NO_WARNINGS
#include"better_contact.h"
int main()
{
	Contact con;
	Init_contact(&con);
	int input;
	do 
	{
		menu();
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
			Clean_contact(&con);
			break;
		case 7:
			Sort_contact(&con);
			break;
		case 0:
			Save_contact(&con);
			Destory_contact(&con);
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ\n");
			break;
		}
	} while (input);
	return 0;
}