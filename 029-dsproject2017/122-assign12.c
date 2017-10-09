#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//#include "nikh.c"
COMPLAINT*ina=NULL;
void printi(COMPLAINT*current)
{
	while(current!=NULL)
	{
		printf("%s  , %s\nThe status of the complaint is ' %s '\n\n",current->usernm,current->complain,current->status);
		current=current->next;
	}
}
void selectingoptions12(store*value);
void loginaccount(store*value);
void printcomplaint(COMPLAINT*x)
{
	while(x!=NULL)
	{
		printf("%s\n",x->usernm);
		x=x->next;
	}
}
void delete(COMPLAINT*x,COMPLAINT*y)
{
	int count=0;
	COMPLAINT*pre=x;
	while(x!=NULL)
	{
		if(!strcmp(x->usernm,y->usernm))
		{
			break;
		}
		count++;
		pre=x;
		x=x->next;
	}
	if(count==0)
	{
		x=x->next->next;
	}
	else
	{
		if(x->next==NULL)
		{
			x=NULL;
		}
		else
		{
			x=x->next->next;
		}
	}
}
void status(store*value,char*z)
{
	
	int n;
	char m[3][20]={"Rejected :-(","In process :-|","Completed :-)"};
	while(value!=NULL)
	{
		if(value->complain!=NULL)
		{
			if(!strcmp(value->cor,z))
			{
				COMPLAINT*dummy=value->complain;
				
				while(dummy!=NULL)
				{
					COMPLAINT *z=(COMPLAINT*)malloc(sizeof(COMPLAINT));
					printf("%s %s\n",dummy->office,dummy->usernm);
					printf("%s\n",dummy->complain);
					printf("choose any options\n");
					printf("0 for rejected\n1 for inprocess\n2 for completed\n");
					scanf("%d",&n);
					strcpy(dummy->status,m[n]);
					if(n==0)
					{
						//delete(x,y);
						strcpy(z->complain,dummy->complain);
						strcpy(z->usernm,dummy->usernm);
						strcpy(z->office,dummy->office);
						strcpy(z->status,dummy->status);
						//strcpy(z->feedback,y->feedback);
						z->next=NULL;
						z->next=ina;
						ina=z;
					}
					if(n==2)
					{
						printf("your process is succesfully completed\n");
				
					}
					printf("1 for next complaint\n2 for exit\n");
					scanf("%d",&n);
					switch(n)
					{
						case 1:
							dummy=dummy->next;
						break;
						case 2:
							return;
					}
				}
				break;
			}
		}
		value=value->next;
	}
	
}
bool checkpasswd(char*s,int count,store*x,char*y)
{
	char a[100];
	scanf("%s",a);
	if(count==3)
	{
		printf("your passwd is incorrect\n");
		return 0;
	}
	else if(!strcmp(s,a))
	{
		//printf("gsdjgjsdk\n");
		system("clear");
		status(x,y);
		//printing();
		return 1;
	}
	else
	{
		printf("enter the passwd again");
		return checkpasswd(s,count+1,x,y);
	}
}
void loginaccount(store*x)
{
	char ua2[1000],ua3[100],ua5[100];
	int j=0;
	printf("Enter User name to login : ");
	scanf("%s",ua3);
	while(x!=NULL)
	{
		if(!strcmp(ua3,x->cor))
		{
		j=1;
			int z;
			printf("Enter your password to login : ");
			z=checkpasswd(x->passwd,0,x,x->cor);
			if(z==0)
			{
				//selectingoptions12(x);
				break;
			}
			else
			{
				
				break;
			}	
		}
		x=x->next;
	}
	if(j==0)
	{
		printf("your username is wrong pls type again or register\n");
		selectingoptions12(x);
	}
}
bool loginsuper(char *x,int count)
{
	char a[100];
	scanf("%s",a);
	if(count==3)
	{
		printf("your passwd is incorrect\n");
		return 0;
	}
	else if(!strcmp(x,a))
	{
		supercheck();
		return 1;
	}
	else
	{
		printf("enter the passwd again");
		return loginsuper(x,count+1);
	}
}
void superuser1(store*value)
{
	char cor[100],passwd[100];
	int x;
	printf("enter your super user to login:");
	scanf("%s",cor);
	if(!strcmp(cor,superuser->cor))
	{
		printf("please enter ur passwd\n");
		x=loginsuper(superuser->passwd,0);
		if(!x)
		{
			selectingoptions12(value);
		}
	}
	else
	{
		printf("user does not exist\n");
		selectingoptions12(value);
	}
}
void selectingoptions12(store*value)
{
	int x,y;
	printf("\n\t\t\t\t\t\t\t\t\t\t\tWelcome to ADMIN login\n");
	printf("Enter '1' to create an ADMIN account.\nEnter '2' to login into ADMIN account.\nEnter '3' to login as SuPeRuSeR.\nEnter '4' to exit.\n");
	printf("Enter your option : ");
	scanf("%d",&x);
	printf("\n");
	switch(x)
	{
		case 1:
			system("clear");
			value=createaccount(value);
			if(checkvalue==0)
			{
				selectingoptions12(value);
			}
			printf("\t\t\t\t\t\t\t\t\t\tYou have successfully registered an account.\n");
			selectingoptions12(value);
			break;						
		case 2:
			system("clear");
			loginaccount(value);
			superuser->inap=ina;
			selectingoptions12(value);
			break;
		case 3:
			superuser1(value);
			selectingoptions12(value);
			break;
		case 4:
			break;
	}
}
