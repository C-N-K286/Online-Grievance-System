#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
//#include "USER.c"
//FIRST FOR CREATING NODE AND STORING INFORMATION FROM USER.TXT
typedef struct node{
	char user[15];
	double userid;
	double aadhar;
	char group[10];
	struct node*next;
}NODE;
//FIRST FOR CREATING NODE1 AND STORING INFORMATION FROM COMPLAINTS.TXT
typedef struct node1{
	char name[15];
	char govt[15];
	char complaint[100];
	char status[10];
	int feedback;
	struct node1*next;
}NODE1;
NODE*head=NULL;
NODE*current=NULL;
NODE1*head1=NULL;
NODE1*current1=NULL;


void NGO();
void socialcauses();
//CREATING FIRST NODE WHEN LIST IS EMPTY FOR USER.TXT
void createnode(char ug4[100][100])
{
	NODE*p=(NODE*)malloc(sizeof(NODE));
	strcpy(p->user,ug4[0]);
	p->userid=atoi(ug4[1]);
	p->aadhar=atoi(ug4[2]);
	strcpy(p->group,ug4[3]);
	p->next=NULL;
	head=current=p;
}



//CREATING LINKED LIST FOR USER.TXT 
void insertnode(char ug4[100][100])
{
	if(head==NULL)
	{
		createnode(ug4);
	}
	else
	{
		NODE*p=(NODE*)malloc(sizeof(NODE));
		strcpy(p->user,ug4[0]);
		p->userid=atoi(ug4[1]);
		p->aadhar=atoi(ug4[2]);
		strcpy(p->group,ug4[3]);
		p->next=NULL;
		head->next=p;
		head=p;
	}


}



//CREATING FIRST NODE WHEN LIST IS EMPTY FOR COMPLAINTS.TXT
void createnode1(char pg4[100][100])
{
	NODE1*p=(NODE1*)malloc(sizeof(NODE1));
	strcpy(p->name,pg4[0]);
	strcpy(p->govt,pg4[1]);
	strcpy(p->complaint,pg4[2]);
	strcpy(p->status,pg4[3]);
	p->feedback=atoi(pg4[4]);
	p->next=NULL;
	head1=current1=p;
}



//CREATING LINKED LIST FOR COMPLAINTS.TXT

void insertnode1(char pg4[100][100])
{

	if(head1==NULL)
	{

		createnode1(pg4);

	}
	else
	{


		NODE1*p=(NODE1*)malloc(sizeof(NODE1));
		strcpy(p->name,pg4[0]);
		strcpy(p->govt,pg4[1]);
		strcpy(p->complaint,pg4[2]);
		strcpy(p->status,pg4[3]);
		p->feedback=atoi(pg4[4]);
		p->next=NULL;
		head1->next=p;
		head1=p;

	}
}


//CONVERTING AND EXTRACTING INFORMATION FROM THE FILES USER.TXT AND COMPLAINTS.TXT AND STORING IN THE 2D CHARACTER ARRAY AND PASSING IT
void convert()
{	

	char ua2[1000],ua3[100],ug4[100][100],ua5[100];
	FILE*fp=fopen("user.txt","r");
	while(fgets(ua2,sizeof(ua2),fp)!=NULL)
	{

		int i=0,j=0,k=0;

		while(ua2[i]!='\n')
		{
			if(ua2[i]==',')
			{
				ug4[k][j]='\0';
				j=0;
				k++;
			}
			else
			{
				ug4[k][j]=ua2[i];
				j++;
			}
			i++;
		}

		insertnode(ug4);

	}

	char pa2[1000],pa3[100],pg4[100][100],pa5[100];
	FILE*fz=fopen("complaints.txt","r");
	while(fgets(pa2,sizeof(pa2),fz)!=NULL)
	{

		int i=0,j=0,k=0;

		while(pa2[i]!='\n')
		{
			if(pa2[i]==',')
			{
				pg4[k][j]='\0';
				j=0;
				k++;
			}
			else
			{
				pg4[k][j]=pa2[i];
				j++;
			}
			i++;
		}

		insertnode1(pg4);

	}fclose(fz);
	fclose(fp);

}



//PRINTING MEMBERS IN THE B.I.N.G.O OR E.N.G.O GROUPS UPDATED AND INITIAL MEMBERS ALSO

void printlist(char a[100][100],int i,char b[100][100],int j)
{  


	int p=0;
	printf("B.I.N.G.O GROUP MEMBERS:\n");
	for(p=0;p<=i+1;p++)
	{
		printf("%s\n",a[p]);
	}
	printf("E.N.G.O GROUP MEMBERS:\n");
	for(p=0;p<=j+1;p++)
	{
		printf("%s\n",b[p]);
	}
}




//JOINING IN B.I.N.G.O GROUP AND SEEING THE UPDATED B.I.N.G.O GROUP MEMBERS AND EXIT ALSO(OPTIONAL)


void BINGO(char a[100][100],int i,char b[100][100],int j,char flag[10])
{
	char ch[100];
	int x=0,t,m,temp=1,l;


	do
	{


		if(x==0)
		{
			printf("enter ur name:");

		}
		else
		{
			m=0,l=0;
			while(m<j,l<i){
				if(strcmp(b[m],ch)!=0 && strcmp(a[l],ch)!=0)
				{
					temp=1;
				}
				else
				{
					temp=0;
					break;


				}      	
				m++;l++;
			}
			if(temp==1)
			{

				printf("\n****USER NOT AVAILABLE*****\n");

			}
			else
			{
				printf("you have already opted:\n");
				printf("\nEnter ur name again:\n");
			}
		}
		scanf("%s",ch);
		x=1;
	}
	while(strcmp(ch,flag)!=0);   
	if(strcmp(ch,flag)==0)
	{
		strcpy(a[i],flag);

	}

	printf("ENTER 1 TO SEE UPDATED GROUP MEMBERS:\nENTER 2 TO EXIT\n");

	scanf("%d",&t);

	switch(t){
		case 1:
			printf("UPDATED GROUP MEMBERS:\n");
			printlist(a,i,b,j);
			break;
		case 2:
			printf("EXIT\n");

			char a[100][100],b[100][100];
			int j=0,i=0,ua;
			char flag[10],temp[10];

			while(current->next!=NULL)
			{
				if(strcmp(current->group,"BINGO")==0)
				{
					strcpy(a[i],current->user);
					current=current->next;
					i++;        
				}
				else if(strcmp(current->group,"ENGO")==0)
				{
					strcpy(b[j],current->user);
					current=current->next;
					j++;        
				}
				else
				{

					strcpy(flag,current->user);

					current=current->next;

				}
			}
			printf("1.BINGO group\n2.ENGO group\nEnter 3 to know the details of the members of the groups\nEnter 4 to EXIT\n");
			printf("\nB.I.N.G.O means BUSINESS-FRIENDLY INTRENATIONAL NGO (EXAMPLE:RED CROSS)\nE.N.G.O means ENVIRONMENTAL NGO (EXAMPLE:GREENPEACE and WORLD WILDLIFE FUND)\n");
			scanf("%d",&ua);

			switch(ua){

				case 1:
					printlist(a,i,b,j);
					break;
				case 4:
					NGO();
					break;
				default:
					break;}
		default:
			break;}



}

//JOINING IN E.N.G.O GROUP AND SEEING THE UPDATED E.N.G.O GROUP MEMBERS AND EXIT ALSO(OPTIONAL)

void ENGO(char a[100][100],int i,char b[100][100],int j,char flag[10])
{

	char ch[0];
	int x=0,t,m,temp,l=0;


	do
	{
		if(x==0)
		{
			printf("enter ur name:");

		}
		else
		{	m=0,l=0;
			while(m<j,l<i){
				if(strcmp(b[m],ch)!=0 && strcmp(a[l],ch)!=0)
				{
					temp=1;
				}
				else
				{
					temp=0;
					break;


				}      	
				m++;l++;
			}
			if(temp==1)
			{

				printf("\n****USER NOT AVAILABLE*****\n");

			}
			else
			{
				printf("you have already opted:\n");
				printf("\nEnter ur name again:\n");
			}

		}
		scanf("%s",ch);
		x=1;
	}
	while(strcmp(ch,flag)!=0);
	if(strcmp(ch,flag)==0)
	{
		strcpy(b[j],flag);

	}

	printf("ENTER 1 TO SEE UPDATED GROUP MEMBERS:\nENTER 2 TO EXIT\n");

	scanf("%d",&t);

	switch(t){
		case 1:
			printf("\nUPDATED GROUP MEMBERS:\n");
			printlist(a,i,b,j);
			break;
		case 2:
			printf("EXIT\n");

			char a[100][100],b[100][100];
			int j=0,i=0,ua;
			char flag[10],temp[10];

			while(current->next!=NULL)
			{
				if(strcmp(current->group,"BINGO")==0)
				{
					strcpy(a[i],current->user);
					current=current->next;
					i++;        
				}
				else if(strcmp(current->group,"ENGO")==0)
				{
					strcpy(b[j],current->user);
					current=current->next;
					j++;        
				}
				else
				{

					strcpy(flag,current->user);

					current=current->next;

				}
			}
			printf("1.BINGO group\n2.ENGO group\nEnter 3 to know the details of the members of the groups\nEnter 4 to EXIT\n");
			printf("\nB.I.N.G.O means BUSINESS-FRIENDLY INTRENATIONAL NGO (EXAMPLE:RED CROSS)\nE.N.G.O means ENVIRONMENTAL NGO (EXAMPLE:GREENPEACE and WORLD WILDLIFE FUND)\n");
			scanf("%d",&ua);

			switch(ua){

				case 1:
					printlist(a,i,b,j);
					break;
				case 4:
					NGO();
					break;
				default:
					break;}

		default :
			break;}
}


//STORING THE MEMBERS IN THE RESPECTIVE GROUPS AND THOSE WHO OPTED NOTHING (WHO ARE IN DILEMMA) CAN JOIN IN THE GROUPS 

void NGOgroup()
{

	char a[100][100],b[100][100];
	int j=0,i=0,ua;
	char flag[10],temp[10];

	while(current->next!=NULL)
	{
		if(strcmp(current->group,"BINGO")==0)
		{
			strcpy(a[i],current->user);
			current=current->next;
			i++;        
		}
		else if(strcmp(current->group,"ENGO")==0)
		{
			strcpy(b[j],current->user);
			current=current->next;
			j++;        
		}
		else
		{

			strcpy(flag,current->user);

			current=current->next;


		}
	}
	printf("1.B.I.N.G.O group\n2.E.N.G.O group\nEnter 3 to know the details of the members of the groups\nEnter 4 to EXIT\n");
	printf("\nB.I.N.G.O means BUSINESS-FRIENDLY INTRENATIONAL NGO (EXAMPLE:RED CROSS)\nE.N.G.O means ENVIRONMENTAL NGO (EXAMPLE:GREENPEACE and WORLD WILDLIFE FUND)\n");
	scanf("%d",&ua);

	switch(ua){
		case 1:
			system("clear");
			BINGO(a,i,b,j,flag);
			break;
		case 2:
			system("clear");
			ENGO(a,i,b,j,flag);
			break;
		case 3:
			system("clear");
			printlist(a,i,b,j);
			break;
		case 4:
			NGO();
			break;
		default:
			break;}


}


//ONE OF THE SOCIAL CAUSES (CORRUPTION), LIKES AND DISLIKES FOR THE MATTER GIVEN AND EXIT ALSO
void corruption()
{
	srand(time(NULL));
	int i,N,k;
	printf("						CORRUPTION:\n\n");
	printf("Corruption is widespread in India. India is ranked 76 out of a 179 countries in Transparency International's Corruption Perceptions Index, but its score has improved consistently from 2.7 in 2002 to 3.1 in 2011.In India, corruption takes the form of bribes, tax evasion, exchange controls, embezzlement, etc. A 2005 study done by Transparency International[unreliable source?] (TI) India found that more than 50 percent [dubious – discuss] had firsthand[dubious – discuss] experience of paying bribe or peddling influence to get a job done in a public office.The chief economic consequences of corruption are the loss to the exchequer, an unhealthy climate for investment and an increase in the cost of government-subsidised services.\n\n");
					printf("Reasons:\n1. Low Pay scales/ Wages:\n2. Low Job opportunities.\n3. Option of many political parties:\n4. Lack of Unity in public:\n\n");

	N=rand()%1000+1;k=rand()%10+1;
	int x;
	printf("LIKES:%d                                                          DISLIKES:%d\n\n",N,k);
	printf("type 1 to upadte likes type 2 update dislikes\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			N++;
			printf("%d\n",N);
		case 2:
			break;
	}
	
	printf("ENTER 1 TO EXIT:\n");

	scanf("%d",&i);
	if(i==1)
	{
		system("clear");
		//socialcauses();
	}
}


//ONE OF THE SOCIAL CAUSES (POVERTY), LIKES AND DISLIKES FOR THE MATTER GIVEN AND EXIT ALSO
void poverty()
{
	int i,N,k;
	srand(time(NULL));


	printf("                                                POVERTY:\n\n");
	printf("Poverty is general scarcity or the state of one who lacks a certain amount of material possessions or money.It is a multifaceted concept, which includes social, economic, and political elements. Absolute poverty or destitution refers to the lack of means necessary to meet basic needs such as food, clothing and shelter. Absolute poverty is meant to be about the same independent of location. Relative poverty occurs when people in a country do not enjoy a certain minimum level of living standards as compared to the rest of the population and so would vary from country to country, sometimes within the same country.\n\n");

	printf("									Reasons:						   								\n1.LACK OF EDUCATION\n2.OVERPOPULATION\n3.HIGH DIVERSE RATE\n4.EPIDEMIC DISEASES\n\n");

	N=rand()%1000+1;k=rand()%10+1;
	printf("LIKES:%d                                                          DISLIKES:%d\n\n",N,k);

	printf("ENTER 1 TO EXIT:\n");
	scanf("%d",&i);
	if(i==1)
	{
		system("clear");
		socialcauses();
	}
}


//ONE OF THE SOCIAL CAUSES (FARMER), LIKES AND DISLIKES FOR THE MATTER GIVEN AND EXIT ALSO
void farmer()
{int i,n,N,k;
	printf("						FARMER SUICIDE:\n\n");

	printf("In 2014, the National Crime Records Bureau of India reported 5,650 farmer suicides. The highest number of farmer suicides were recorded in 2004 when 18,241 farmers committed suicide. The farmers suicide rate in India has ranged between 1.4 and 1.8 per 100,000 total population, over a 10-year period through 2005.India is an agrarian country with around 70 percent of its people depending directly or indirectly upon agriculture. Farmer suicides account for 11.2 percent of all suicides in India. Activists and scholars have offered a number of conflicting reasons for farmer suicides, such as monsoon failure, high debt burdens, government policies, public mental health, personal issues and family problems. There are also accusation of states manipulating the data on farmer suicides.\n\n");


	printf("					                           Reasons: \n								        1.DROUGHT\n									2.NEW ECONOMIC POLICY\n									3.GM CROPS\n									4.SUICIDE IDEA\n									5.STATE GOVERNMENT FIELD SURVEYS\n\n");

	N=rand()%1000+1;
	k=rand()%10+1;
	printf("LIKES:%d                                                             DISLIKES:%d\n\n",N,k);
	printf("ENTER 1 TO EXIT:\n");
	scanf("%d",&i);
	if(i==1)
	{
		system("clear");
		socialcauses();
	}

}


//MAIN FUNCTION FOR CALLING ABOVE FUNCTIONS 

void socialcauses()
{
	int n;

	printf("1.FARMERS SUICIDE IN INDIA\n2.POVERTY\n3.CORRUPTION\n4.EXIT\n");
	scanf("%d",&n);
	switch(n){
		case 1:
			// system("clear");
			farmer();
			break;
		case 2:
			system("clear");
			poverty();
			break;
		case 3:
			system("clear");
			corruption();
		case 4:
			system("clear");
			NGO();
		default:
			break;	
	}		
}

//(EXTRA TASK)PRINTING DIFFERENT TYPE OF GRAPH(PERFORMANCE DONE BY GOVERNMENT OFFICIALS ) --BASED ON THE FEEDBACK GIVEN BY THE USERS ON MUNICIPALITY,TAX DEPARTMENT,HEALTH

void graph(int sum,int sum1,int sum2,int count,int count1,int count2)
{
	int x=sum/count;int z=sum1/count1;int y=sum2/count2;
	int i,j,p=10;
	printf("RATING:  ----->POINTS AVERAGE FEEDBACK\n\n\n");
	while(1)
	{
		if(x<=5){
			for(i=1;i<=10-x;i++)
			{printf("%d",p);if(p==10){printf("      ");}else{printf("       ");}
				for(j=1;j<=10;j++)
				{
					printf("|");
					if(x<=5){
						if(j==10&&i==3){

							printf("<------------:GOOD PERFORMANCE:");

						}
						if(j==10&&i==5){
							printf("<------------:AVERAGE PERFORMANCE:");
						}
					}}p--;
				printf("\n");

			}

			for(i=1;i<=x;i++)
			{printf("%d",p);if(p==x){printf("----->");}if(p!=x){printf("       ");}else{printf(" ");}
				for(j=1;j<=1;j++)
				{
					printf("|||    |||");

					if(x<=5)
					{if(x==1 ||i==x-1){

								  printf("<------------:POOR PERFORMANCE:");
							  }
					}



				}p--;
				printf("\n");
			}}

		p=10;
		if(x>5)
		{
			for(i=1;i<=10-x;i++)
			{printf("%d",p);if(p==10){printf("      ");}else{printf("       ");}
				for(j=1;j<=10;j++)
				{

					printf("|");
					if(x==6||x==7){
						if(j==10&&i==3){

							printf("<------------:GOOD PERFORMANCE:");

						}



					}



				}p--;
				printf("\n");
			}

			for(i=1;i<=x;i++)
			{printf("%d",p);if(p==x){printf("----->");}if(p!=x){printf("       ");}else{printf(" ");}
				for(j=1;j<=1;j++)
				{
					printf("|||    |||");

					if(x>5)
					{if(i==x-1){

							   printf("<------------:POOR PERFORMANCE:");
						   }
					if(x==6 && i==1){

						printf("<------------:AVERAGE PERFORMANCE:");
					}
					if(x==7 && i==2)
					{
						printf("<------------:AVERAGE PERFORMANCE:");
					}
					}



				}p--;
				printf("\n");
			}}


		printf("\n         MUNICIPALITY AVERAGE SERVICE TO ALL USERS:%d\n\n",x);



		printf("---------------------------------------------\n");
		p=10;
		if(y<=5){
			for(i=1;i<=10-y;i++)
			{printf("%d",p);if(p==10){printf("      ");}else{printf("       ");}
				for(j=1;j<=10;j++)
				{

					printf("|");
					if(y<=5){
						if(j==10&&i==3){

							printf("<------------:GOOD PERFORMANCE:");

						}
						if(j==10&&i==5){

							printf("<------------:AVERAGE PERFORMANCE:");

						}


					}}p--;
				printf("\n");


			}

			for(i=1;i<=y;i++)
			{printf("%d",p);if(p==y){printf("----->");}if(p!=y){printf("       ");}else{printf(" ");}
				for(j=1;j<=1;j++)
				{
					printf("|||    |||");

					if(y<=5)
					{if(y==1 ||i==y-1){

								  printf("<------------:POOR PERFORMANCE:");
							  }
					}



				}p--;
				printf("\n");
			}}

		p=10;
		if(y>5)
		{
			for(i=1;i<=10-y;i++)
			{printf("%d",p);if(p==10){printf("      ");}else{printf("       ");}
				for(j=1;j<=10;j++)
				{

					printf("|");
					if(y==6||y==7){
						if(j==10&&i==3){

							printf("<------------:GOOD PERFORMANCE:");

						}



					}



				}p--;
				printf("\n");
			}


			for(i=1;i<=y;i++)
			{printf("%d",p);if(p==y){printf("----->");}if(p!=y){printf("       ");}else{printf(" ");}
				for(j=1;j<=1;j++)
				{
					printf("|||    |||");

					if(y>5)
					{if(i==y-1){

							   printf("<------------:POOR PERFORMANCE:");
						   }
					if(y==6 && i==1){

						printf("<------------:AVERAGE PERFORMANCE:");
					}
					if(y==7 && i==2)
					{
						printf("<------------:AVERAGE PERFORMANCE:");

					}

					}



				}p--;
				printf("\n");
			}}

		printf("\n         HEALTH AVERAGE SERVICE TO ALL USERS:%d\n\n",y);
		printf("---------------------------------------------\n");
		p=10;
		if(z<=5){
			for(i=1;i<=10-z;i++)
			{printf("%d",p);if(p==10){printf("      ");}else{printf("       ");}
				for(j=1;j<=10;j++)
				{

					printf("|");
					if(z<=5){
						if(j==10&&i==3){

							printf("<------------:GOOD PERFORMANCE:");

						}
						if(j==10&&i==5){

							printf("<------------:AVERAGE PERFORMANCE:");

						}


					}}p--;
				printf("\n");


			}
			for(i=1;i<=z;i++)
			{printf("%d",p);if(p==z){printf("----->");}if(p!=z){printf("       ");}else{printf(" ");}
				for(j=1;j<=1;j++)
				{
					printf("|||    |||");

					if(z<=5)
					{if(z==1 ||i==z-1){

								  printf("<------------:POOR PERFORMANCE:");
							  }
					}



				}p--;
				printf("\n");
			}}

		p=10;
		if(z>5)
		{
			for(i=1;i<=10-z;i++)
			{printf("%d",p);if(p==10){printf("      ");}else{printf("       ");}
				for(j=1;j<=10;j++)
				{

					printf("|");
					if(z==6||z==7){
						if(j==10&&i==3){

							printf("<------------:GOOD PERFORMANCE:");
						}
					}
				}p--;
				printf("\n");
			}


			for(i=1;i<=z;i++)
			{printf("%d",p);if(p==z){printf("----->");}if(p!=z){printf("       ");}else{printf(" ");}
				for(j=1;j<=1;j++)
				{
					printf("|||    |||");

					if(z>5)
					{if(i==z-1){

							   printf("<------------:POOR PERFORMANCE:");
						   }
					if(z==6 && i==1){

						printf("<------------:AVERAGE PERFORMANCE:");
					}
					if(z==7 && i==2)
					{
						printf("<------------:AVERAGE PERFORMANCE:");

					}

					}



				}p--;
				printf("\n");
			}}
		printf("\n         TAX DEPARTMENT AVERAGE SERVICE TO ALL USERS:%d\n\n",z);

		break;
	}
}


//GETTING FEEDBACK OF DIFFERENT GOVT GROUPS 

void justice()
{
	int a[100];
	int sum=0,sum1=0,sum2=0,count=0,count1=0,count2=0;
	while(current1->next!=NULL)
	{
		if(strcmp(current1->govt,"municipality")==0)
		{
			a[0]=current1->feedback;
			sum=sum+a[0];count++;
			current1=current1->next;

		}
		if(strcmp(current1->govt,"taxdepartment")==0)
		{
			a[1]=current1->feedback;
			sum1=sum1+a[1];count1++;

			current1=current1->next;

		}
		if(strcmp(current1->govt,"health")==0)
		{
			a[2]=current1->feedback;
			sum2=sum2+a[2];count2++;
			current1=current1->next;

		}
	}
	if(current1->next==NULL)
	{
		if(strcmp(current1->govt,"municipality")==0)
		{
			a[0]=current1->feedback;
			sum=sum+a[0];count++;

		}
		if(strcmp(current1->govt,"taxdepartment")==0)
		{
			a[1]=current1->feedback;
			sum1=sum1+a[1];count1++;


		}
		if(strcmp(current1->govt,"health")==0)
		{
			a[2]=current1->feedback;
			sum2=sum2+a[2];count2++;

		}
	}
	graph(sum,sum1,sum2,count,count1,count2);
}


//CALLING ALL THE 3 TASKS HERE

void NGO()
{
	int ng;
	printf("Enter '1' to join in any NGO group\nEnter '2' to view the social problems.\nEnter '3' to view the percentage of the feedback given by users.\n 4 for exit\n");
	scanf("%d",&ng);
	switch(ng){	
		case 1:
			system("clear");
			NGOgroup();
			break;
		case 2:
			system("clear");
			socialcauses();
			break;
		case 3:
			justice();
			break;	
		case 4:
			return;
	}
}	
