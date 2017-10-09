#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
/*structure for storing complaints and admin username in linked list*/
typedef struct contents
{
	char cor[100];
	char passwd[100];
	COMPLAINT*complain;/*complaints taken from the user structure*/
	struct contents *next;;
	
}store;
/*structure for super user*/
typedef struct super
{
	char cor[100];
	char passwd[100];
	COMPLAINT*inap;
}USER;
USER*superuser;
int checkvalue=0;
/*creates a new node and return it*/
store*newnode(char s[][100])
{
	store*new = (store *) malloc(sizeof(store));/*allocating memory*/
	if (new == NULL) exit(-1);
	strcpy(new->cor,s[0]);
	strcpy(new->passwd,s[2]);
	new->next = NULL;
	return new;
}
/* funcion below is used to create a new account for new admin*/
store*createaccount(store*value)
{
		char s[100][100];
		int ua1=0;
		printf("Enter Ur corporation:");
		getchar();
		scanf("%[^\n]s",s[0]);
		store *value1;
		value1=value;
		/*while searches for exisiting user*/
		while(value1!=NULL)
		{
			if(!strcmp(value1->cor,s[0]))
			{
				printf("username already exists please login\n");	
				checkvalue=0;
				return value;
			}
			value1=value1->next;
		}
		checkvalue=1;
		/* do-while loop for unique aadhar card with value greater than 12 digits*/
		do
		{
			if(ua1==0)
			{
			printf("Enter ur unique aadhar number:");
			}
			else
			{
			printf("Unique aadhar number must contain 12 digits:\n");
			}
			scanf("%s",s[1]);
			ua1=1;
		}
		/*do-while loop taking passwd for greater than length 8*/
		while(!(strlen(s[1])==12));
				ua1=0;
		do
		{
			if(ua1==0)
			{
			printf("Enter ur Password:");
			}
			else
			{
			printf("Password must be grater than length 8:\n");
			}
			scanf("%s",s[2]);
			ua1=1;
		}
		while(!(strlen(s[2])>=8));
		memset(s[3],sizeof(s[3]),'\0');
		FILE*fp=fopen("admin.txt","a");
		store *x;
		x=newnode(s);
		x->next=value;
		value=x;
		ua1=0;
		/*storing the 2d arrays in file*/
		while(s[ua1][0]!='\0')
		{
			fprintf(fp,"%s,",s[ua1]);
			ua1++;
		}
		fprintf(fp,"%c",'\n');
		fclose(fp);
		return value;
}
/*this function is used to read the file and store the passwd in doubly Linked List*/
store* adminstore(store*value)
{
char ua2[1000],ua4[100][100];
	FILE *fp=fopen("admin.txt","r");
	/*reading the lines form file*/
	while(fgets(ua2,sizeof(ua2),fp)!=NULL)
	{
		int i=0,j=0,k=0;
		/*storing the values in lines 2d array*/
		while(ua2[i]!='\n')
		{
			if(ua2[i]==',')
			{
				ua4[k][j]='\0';
				j=0;
				k++;
			}
			else
			{
				ua4[k][j]=ua2[i];
				j++;
			}
			i++;
		}
		store *x;
		x=newnode(ua4);/*passing the array to create new node and storing the node in linked list by inserting at first*/
		x->next=value;
		value=x;
		}
		return value;
}
/*function to check*/
void printxyz(store*x)
{
	while(x!=NULL)
	{
		printf("%s\n",x->cor);
		x=x->next;
	}
}
/*function will store the complaints from the user and attach the file to respective admin*/
void storerespective(COMPLAINT*ua,store*ua2)
{
	int j=0;
	store*ua1=ua2;
	while(ua1!=NULL)
	{
		//printf("%s\n",ua1->cor);
		/*storing the complaints in respective corporation*/
		if(!strcmp(ua1->cor,ua->office))
		{
			j=1;
			COMPLAINT*new=(COMPLAINT*)malloc(sizeof(COMPLAINT));
			new=ua;
			new->next=ua1->complain;
			ua1->complain=new;
			//printf("%s\n",ua->usernm);
			break;
		}
		ua1=ua1->next;
	}
	ua1=ua2;
	if(j==0)
	{
		while(ua1!=NULL)
		{
			if(!strcmp(ua1->cor,"other"))
		{
			COMPLAINT*new=(COMPLAINT*)malloc(sizeof(COMPLAINT));
			new=ua;
			new->next=ua1->complain;
			ua1->complain=new;
			break;
		}
		ua1=ua1->next;
		}
	}
}
/*function will traverse from one user to user and call the storerespective functions*/
store*sortcompliants(store*value,PROFILE*profile)
{
	PROFILE *ua;
	ua=profile;
	while(ua!=NULL)
	{
		if(ua->uinfo!=NULL)
		{
			//printf("dhgdj");
			storerespective(ua->uinfo,value);	
		}
		ua=ua->next;
	}
}
/*super user login and complaints*/
void supercheck()
{
	COMPLAINT *dummy;
	dummy=superuser->inap;
	int feedback;
	int n;
	if(dummy==NULL)
	{
		printf("there are no complaints");
		return;
	}
	else
	{
		while(dummy!=NULL)
		{
			printf("%s %s\n",dummy->office,dummy->usernm);
			printf("%s\n",dummy->complain);
			char m[3][20]={"Rejected :-(","Completed :-)"};
			printf("choose any options\n");
			printf("0 for rejected\n1 for completed\n");
			scanf("%d",&n);
			strcpy(dummy->status,m[n]);
			if(n==1)
			{
				printf("your process is succesfully completed\n");
				//getchar();
				printf("Pls.. submit feedback in rate of 1 to 10\n");
				printf("%d",feedback);
				dummy->feedback=feedback;
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
	}
}

