#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
typedef struct complaint{
	char complain[200];
	char usernm[100];
	char office[30];
	char status[20];
	int feedback;
	struct complaint *next;
}COMPLAINT;
typedef struct profile
{
	char usernm[20];
	long int uid;
	char password[20];
	char ngo[20];
	struct complaint *uinfo; 
	struct profile *next;
} PROFILE ;
int checkvalue1=0;
//--------------------------------------------------------------
//ALL FUNCTIONS INVOLVED IN THIS CODE
void loggedin(PROFILE *temp); // THIS CODE RUNS WHEN USER LOGGED IN
COMPLAINT*insertcomplaint(char *u1); //IT INSERTS COMPLAINTS TO CERTAIN USER ACCORDING TO USER NAME
PROFILE *TaskOne(); //IT READS DATA FROM FILE AND SAVES INTO LINKED LIST
void comstatus(PROFILE *temp);// THIS FUNCTION GIVES STATUS OF A COMPLAINT
void submitfeedback(PROFILE *temp);// SUBMISSION OF FEEDBACK 
void issuecompliant(PROFILE *tem);// ISSUES COMPLAINTS
void login(char s[],PROFILE *root);//USED FOR USER AUTHENTICATION
void loop(PROFILE *profile);//IT STARTS PROGRAM
void registering();//ADDS NEW USERS
int checkuser(PROFILE  *temp,char s[]);//CHECK WHEATHER USER EXISTS OR NOT WITH GIVEN USER NAME WHILE REGISTERING
void joinngo(PROFILE *temp);//PROMTS USER TO JOIN IN NGO'S WHILE REGISTERING
//--------------------------------------------------------------

//--------------------------------------------------------------
//---------------------------------------------------------------
void loop(PROFILE *profile);
PROFILE *root;
int urlogattempt=1;
//------------------------------------------------------------------
//-----------------------------------------------------------------------------        
//functions

PROFILE *insertItem(PROFILE *profile)
{
	PROFILE *count;
	count=root;
	while(count->next!=NULL)
	{	
		count=count->next;
	}
	count->next = profile;
	profile->next = NULL;

}
//-----------------------------------------------------------------
COMPLAINT *insertcomplaint(char *u1)
{
	char h[10][300];
	char a[1000];
	int k=0;
	FILE*fp=fopen("complaints.txt","r");
	COMPLAINT*x;
	x=(COMPLAINT *)malloc(sizeof(COMPLAINT));
	while (fgets(a,sizeof(a),fp)!=NULL )
	{
		int j=0,k=0;

		for( int i=0;a[i]!='\0';i++)
		{
			if(a[i]==',' || a[i]=='\n')
			{
				h[j][k]='\0';
				k=0;j=j+1;

				continue;
			}
			else {

				h[j][k]=a[i];
				k=k+1; 

			}
			h[j][k+1]='\0';	
		}
		if(!strcmp(u1,h[0]))
		{
			k=1;
			strcpy(x->office,h[1]);
			strcpy(x->complain,h[2]);
			strcpy(x->status,h[3]);
			x->feedback=atoi(h[4]);
			return x;
		}	
	}
	if(k==0)
	{
		x=NULL;
		return x;
	}
}
//------------------------------------------------------------------
PROFILE *TaskOne()
{
	FILE *fp;
	PROFILE *g;

	char h[10][300];
	char a[1000];

	g=(PROFILE *) malloc(sizeof(PROFILE));
	g->next=NULL;
	g->uinfo=NULL;
	root=g;
	fp=fopen("user.txt","r");
	int i;
	while (fgets(a,sizeof(a),fp)!=NULL )
	{
		int j=0,k=0;

		for( int i=0;a[i]!='\0';i++)
		{
			if(a[i]==',' || a[i]=='\n')
			{
				k=0;j=j+1;
				continue;
			}
			else {

				h[j][k]=a[i];
				k=k+1; 

			}
			h[j][k+1]='\0';	
		}	
		g=(PROFILE*) malloc(sizeof(PROFILE));
		strcpy(g->usernm,h[0]);
		g->uid=atoi(h[1]);
		strcpy(g->password,h[2]);
		g->uinfo=NULL;
		insertItem(g);
		//printf("%s\n",g->usernm);
		//g->uinfo=NULL;
		g->uinfo=insertcomplaint(h[0]);
		if(g->uinfo!=NULL)
		{strcpy(g->uinfo->usernm,g->usernm);}
		memset(a,sizeof(a),'\0');

		for(i=0;i<10;i++)
			memset(h[i],sizeof(h[i]),'\0');
	}
	fclose(fp);
	return root;
}
//----------------------------------------------------------------

void comstatus(PROFILE *temp)
{
	if(temp->uinfo!=NULL){
	printf("______________________________________________________	_________________\n>>>   yours compliant status is: ");
	printf("%s\n__________________________________________________________________________",temp->uinfo->status);
	loggedin(temp);
}	

	else
	{
	printf("No compliants!!!!\n");
	}

}

//----------------------------------------------------------------
void submitfeedback(PROFILE *temp)

{	
	if(temp->uinfo!=NULL){
	int feed;
	printf("Enter your feedback (1-10):");
	scanf(" %d",&feed);
	if(feed < 1  || feed >10)
	{
	printf("feedback must be in range 1-10\n");
	submitfeedback(temp);	
	}
	else{
	temp->uinfo->feedback=feed;
	printf("thanks for your feed back!!!!!\n");
	}
	}
	else
	{
	printf("no compliants exists to submit feedback!!!!\n");
	}
loggedin(temp);
}
//----------------------------------------------------------------
void issuecompliant(PROFILE *tem)
{	
	int i=1;
	if(tem->uinfo!=NULL)
	if(strcmp(tem->uinfo->status,"solved")!=0)
	{
	printf("Your previous compliant is yet to be fixed.If u still want to continue and to replace it by newer one\n'1' to continue.\n'2' to go back.\nEnter your option:");
	scanf("%d",&i);	
	}
	
	if(i==2)
	{
	loggedin(tem);
	}
	if(i==1)
	{	
	FILE *fp;
	COMPLAINT *x=(COMPLAINT*) malloc(sizeof(COMPLAINT));
	char s[200],office[30];
	fp=fopen("complaints.txt","a+");
	fprintf(fp,"%s,",tem->usernm);
	
	printf("Enter the department on which u want to give complaint : ");
	scanf("%s",office);
	strcpy(x->office,office);
	fprintf(fp,"%s,",office);
	getchar();
	printf("\n");
	printf("Enter your compliant (in less than 200 characters ) : ");
	scanf("%[^\n]s",s);
	strcpy(x->complain,s);
	strcpy(x->status,"Submitted for review");
	fprintf(fp,"%s,",s);
	fprintf(fp,"sent to office,");
	fprintf(fp,"%d,\n",x->feedback);
	
	tem->uinfo=x;
	printf("\n");
	printf("Compliant is submitted to the ADMIN !!!\n");
	fclose(fp);
	loggedin(tem);
	}
if(i!=1&&i!=2)
{
printf("Wrong option !!!\n");
issuecompliant(tem);
}

}
//--------------------------------------------------------------------
void savedata()
{
FILE *fp;
fp=fopen("complaints.txt","w");
PROFILE *temp;
temp=root->next;
while(temp!=NULL)
{
if(temp->uinfo!=NULL)
{
fprintf(fp,"%s,%s,%s,%s,%d,\n",temp->usernm,temp->uinfo->office,temp->uinfo->complain,temp->uinfo->status,temp->uinfo->feedback);
}
temp=temp->next;
}
fclose(fp);
}
//--------------------------------------------------------------------
void loggedin(PROFILE *temp)
{
	printf("\nWhat you want to do ??\nPress '1' for issuing a complaint.\nPress '2' for checking your complaint status.\nPress '3' to submit feedback.\nPress '4' to logout\n");
	int k;
	printf("Your option : ");
	scanf("%d",&k);
	switch(k)
	{
		case 1:
			issuecompliant(temp);
			break;
		case 2:
			comstatus(temp);
			break;
		case 3:
			submitfeedback(temp);
			break;
		case 4:
			printf("User logged out succesfully :-)\n");
			savedata();
			loop(root);
			break;	
	}
}
//---------------------------------------------------------
void login(char s[],PROFILE *root)
{
	PROFILE *temp;
	temp=root;
	char pwd[20];
	int i=0;
	if(temp!=NULL)
	if(strcmp(temp->usernm,s)==0)
	{
		printf("Hello '%s' !!! Enter your password : ",temp->usernm);
		scanf("%s",pwd);
		if(strcmp(temp->password,pwd)==0)
		{
			i=1;
		printf("Welcome '%s' !!!\n",temp->usernm);
	
			loggedin(temp);
			
		}
		if(urlogattempt<4&&i==0)
		{
			printf("Wrong password authentication denied !!! :-(\n");
			urlogattempt++;
			login(s,root);
			
		}
		if(urlogattempt==4)
		{urlogattempt=0;
		printf("Login blocked!!! :-(\n");
		loop(root);
		}
	}
	else if(temp->next!=NULL)
	{
		temp=temp->next;
		login(s,temp);
	}
	else if(temp->next==NULL)
	{
		printf("User name not found !!! :-(\n");
	}
	loop(root);
}
//------------------------------------------------------------------------
void joinngo(PROFILE *temp)

{
	char i;
	printf("Please select one in the following NGO's:\nEnter '1' to join in B.I.N.G.O .\nEnter '2'to join in E.N.G.O .\nEnter '3' to join none.\n");
	printf("Interested in N.G.O : ");
	getchar();
	scanf("%c",&i);
	if(i=='1')
		strcpy(temp->ngo,"BINGO");
	else if(i=='2')
		strcpy(temp->ngo,"ENGO");
	else
		strcpy(temp->ngo,"NULL");

}
//-----------------------------------------------------------------------
int checkuser(PROFILE  *temp,char s[])
{
while(temp!=NULL)
{
if (strcmp(temp->usernm,s)==0)
	{
	printf("Username already exists!!! :-D \nTry another username\n");
	registering();
	return 0;
	}
	temp=temp->next;
}
return 1;
}

//------------------------------------------------------------------------
void registering()
{	
	FILE *fp;
	long int adn;
	int n,k=0,i=0;
	char s[10][20];
	PROFILE *new_node,*current,*temp;
	new_node=(PROFILE*)malloc(sizeof(PROFILE));
	printf("Choose your new Username:");
	scanf("%s",s[i]);
	k=checkuser(root->next,s[i]);
	if (k==1)
	{
	strcpy(new_node->usernm,s[i]);
	i++;
	while(1)
	{
	printf("Enter your mobile Number:");
	getchar();
	scanf(" %ld",&adn);
	//printf("%ld")
	if(adn > 6999999999 && adn < 10000000000)	
	{
	new_node->uid=adn;
	break;
	}
	else
	{
	printf("Invalid Mobile Number!!!\n");
	}
	}
	i++;
	printf("Choose your password:");
	scanf("%s",s[i]);
	strcpy(new_node->password,s[i]);
	i++;
	fp=fopen("user.txt","a+");
	joinngo(new_node);
	for(i=0;i<3;i++)
		if (i==1)
		fprintf(fp,"%ld,",adn);
		else 
		fprintf(fp,"%s,",s[i]);
	
	fprintf(fp,"%s,",new_node->ngo);
	fprintf(fp,"\n");
	fclose(fp);
	new_node->next=NULL;
	insertItem(new_node);
	for(i=0;i<10;i++)
		memset(s[i],sizeof(s[i]),'\0');
	}
}
//-----------------------------------------------------------------
void loop(PROFILE *profile)
{

	printf("\n\t\t\t\t\t\t\t\t\t\tWelcome to User login\n\n");
	FILE *fp;
	printf("Enter '1' to signup for an User account.\nEnter '2' to login into user account.\nEnter '3' to exit\n");
	TaskOne();
	char n[100];
	printf("Enter your option : ");
	int opt=0;
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			system("clear");
			registering();
			system("clear");
		       printf("\n\t\t\t\t\t\t\t\t\tYou have succesfully registered an User account :-)\n\n");
		       loop(profile);
		       break;
		case 2:
		    	system("clear");
		       printf("Enter your user name :");
		       scanf("%s",n);
		       login(n,root->next);
		     
		       break;
		case 3:
			system("./a.out");
			break;
	}
}
