#include<stdio.h>
#include<stdlib.h>
#include "colors.c"
#include "108-assign12.c"
#include "123-assign12.c"
#include "122-assign12.c"
#include "101-assign12.c"
//void calling(store);
void calling(store *value,PROFILE*profile)
{
	printf("Enter '1' for admin login.\nEnter '2' for user login.\nEnter '3' to NGO's interface.\nEnter '4' for exit\n");
	int x;
	printf("Enter the option : ");
	scanf("%d",&x);
	system("clear");
	switch(x)
	{
		case 1:
			printingadmin();
			printf("                                   ");
			printf(BBLU"Admin's Website\n"RESET);
			selectingoptions12(value);
			if(checkvalue1==0)
			{
				calling(value,profile);
			}
			break;
		case 2:
			printing();
			printf("                                   ");
			printf(BGRN"Users's Website\n"RESET);
			loop(profile);
			if(checkvalue1==0)
			{
				calling(value,profile);
			}
			break;
		case 3:
			printingngo();
			printf("                                   ");
			printf(BCYAN"NGOs's Website\n"RESET);
			NGO();
			if(checkvalue1==0)
			{
				calling(value,profile);
			}
			break;
		case 4:
			printf("                                   ");
			printf(BYEL "Thank you\n"RESET);
			break;
	}
}
int main()
{
	printf("                                   ");
	printf(BRED"ONLINE GRIEVANCE SYSTEM BY XERTRION.COC\n"RESET);
	//system("clear");
	superuser=(USER*)malloc(sizeof(USER));
	strcpy(superuser->cor,"xertion");
	strcpy(superuser->passwd,"xertion");
	srand(time(NULL));
	store *value=NULL;
	value=adminstore(value);
	ina=(COMPLAINT*)malloc(sizeof(COMPLAINT));
	root=(PROFILE*)malloc(sizeof(PROFILE));
	PROFILE *profile;
	FILE *fp;
	profile=TaskOne();
	profile=profile->next;
	sortcompliants(value,profile);
	 convert();
	calling(value,profile);

} 
