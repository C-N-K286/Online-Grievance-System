Project-Online​   Grievance redressal System 
Group -name =Xertrion.coc
Group-no=29
----------------------------------------------------------------------------------------------------------------------------------------------------
Group-members
1)Nikhil Kumar Chilagani-nikhilkumar.c16@iiits.in
2)Hemanth Kumar Yelluru-hemanthkumar.y16@iiits.in
3)Naga Siva Krishna Chervugattu-nagasivakrishna.c16@iiits.in
4)Sri Harsha Varri-sriharsha.v16@iiits.in
-----------------------------------------------------------------------------------------------------------------------------------------------------
project-Online Grievance Redressal System is a Project which is created to bring transparency 
	and flexibility in the administration system. This system is a online platform where people 
	can share ideas, invoke discussion, issue complaints and create suggestion/petitions for 
	the improvement of the city administration. This application is an automated process 
	which is a user-friendly online interface for the users. 
------------------------------------------------------------------------------------------------------------------------------------------------------
Task no1-Admin:
	Creates and monitors accounts of authorities. Filters the content reported as handle 
	threats. Handle complaints about improper response by municipal authorities. 
used data structure-Doubly Linked List(both up and down traversals)
Functions:
1)store*createaccount(store*value)
	This account will create the all admin's account 
	Input:
		1)The user have to give his name,if name already exists it will call itself
		2)It will ask for aadhar card no,the No should be greater than 12 digits
		3)It will ask for password andthe length of password should be greater than 8 letters
		All the data is stored in form of strings in 2d-array
	Output:
		The above information is stored in file and in double-linked list
2)store*sortcompliants(store*value,PROFILE*profile)
		Input:
			1)Takes the input from the linked list of user
			2)the function will traverse from one user account to another user account and sort the complaints according their corporation
			2) calls one sub functions:
				1)void storerespective(COMPLAINT*ua,store*ua2)
					It will sort complaints to the respective corporation and creates a new node to store to the corporation
		Output:
			1)All complaints are stored to the respective corporation linked list
3)store* adminstore(store*value)
	Store the admin username and password in double linked list from file
	input:
		file
	output:
		admins are stored in linked list
4)void supercheck()
	A special person who recieves all the rejected the complaints and inappropriate from the admins
	He has different structure which has pre defined username and passwd
	supercheck:
		This function reads all the rejected complaints from the admin and deal with them
--------------------------------------------------------------------------------------------------------------------------------------------------------------

A. Users (Citizens) :
Users should be able to create new account, log-in to their existing accounts which will give them the authority to use the services
provided by the system. Authenticated users should be able to issue complaints, check
complaint status, submit feedback;
--------------------------------------------------------------------------------------------------------------------------------------------------------------

                                                   ALl FUNCTIONS in USER MODULE
						   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

task 2.1:( starting program and creating accounts )

void startprogram(PROFILE *profile);       -----> IT STARTS PROGRAM
void registering();                        -----> ADDS NEW USERS
int checkuser(PROFILE  *temp,char s[]);    -----> CHECK WHEATHER USER EXISTS OR NOT WITH GIVEN USER NAME WHILE REGISTERING
void joinngo(PROFILE *temp);               -----> PROMTS USER TO JOIN IN NGO'S WHILE REGISTERING 

task 2.2: ( user logged in display and it's fuunctions)

void login(char s[],PROFILE *root);   	    -----> USED FOR USER AUTHENTICATION	
void loggedin(PROFILE *temp);              -----> THIS CODE RUNS WHEN USER LOGGED IN		 
PROFILE *loaddatafromfile();               -----> IT READS DATA FROM FILE AND SAVES INTO LINKED LIST	

task 2.3: (issuing compliant and saving it database i.e file) 
		 
								 
void issuecompliant(PROFILE *tem);         -----> ISSUES COMPLAINTS								 
COMPLAINT*insertcomplaint(char *u1);       -----> IT INSERTS COMPLAINTS TO CERTAIN USER ACCORDING TO USER NAME									 
	


task 2.4: ( status of users compliant and rate about the progress of compliant )

	 
void comstatus(PROFILE *temp);             -----> THIS FUNCTION GIVES STATUS OF A COMPLAINT		 
void submitfeedback(PROFILE *temp);        -----> SUBMISSION OF FEEDBACK 	

----------------------------------------------------------------------------------------------------------------------------------------------------
							OFFICERS'MODULE--->THIRD TASK
						___________________________________________
						

THIS TASK CONSISTS OF THE FUNCTIONALITIES LIKE	(1) LOGIN TO THEIR ACCOUNTS GIVEN BY 'ADMIN',
						(2) OFFICER CAN ACCESS ALL THE COMPLAINTS,
						(3) INVOKE PROPER ACTIVITY IN RESPONSE TO THE VALID COMPLAINTS AND
						(4) REDIRECT INAPPROPRIATE COMPLAINTS TO THE ADMIN.
					
FUNCTIONS IN THE TASK : (1) void loginaccount(store*value);
			   THIS FUNCTION ALLOWS THE OFFICER TO LOGIN INTO THEIR ACCOUNT GIVEN BY ADMIN.
			   (a) IT ASKS FOR THE USERNAME OF THE OFFICER LOGIN [HERE IT IS DEPARTMENT NAME LIKE HEALTH,TAXDEPARTMENT,MUNICIPALITY]
			   
			   (b) IT ASKS FOR THE PASSWORD FOR THE RESPECTIVE DEPARTMENT WHICH ARE TAKEN FROM FILE "ADMIN.txt".U CAN GIVE THE WRONG PASSWORD ONLY THREE TIMES USING THIS FUNCTION [bool checkpasswd(char*s,int count,store*x,char*y)],AFTER THAT IT WILL EXIT THE PAGE. 
			   
		           (C) AFTER LOGGING INTO A PARTICULAR DEPARTMENT ACCOUNT,[void printi(COMPLAINT*current)]THIS FUNCTION DISPLAYS THE COMPLAINTS OF THE RESPECTIVE DEPARTMENT AND ALSO THE PEOPLE NAMES.
		            
		        (2)void status(store*value,char*z)
		         THIS FUNCTION IS DONE USING LINKEDLISTS FOR STORING THE COMPLAINTS.
		         IT ASKS THE OFFICER TO TAKE ACTION ON THE THAT.
		         'O' TO REJECT THE COMPLAINT.
		         '1' TO PROCESS THE COMPLAINT.
		         '2' TO COMPLETE THE COMPLAINT.
		         
		        (3)void selectingoptions12(store*value);
		        IT IS THE MAIN OFFICER FUNCTION.
		        
		        (4)void delete(COMPLAINT*x,COMPLAINT*y)
		        IT DELETES THE INAPPROPRIATE COMPLAINT AND IT WILL SEND IT TO THE SUPERUSER[HEAD] TO CHECK AND SOLVE THEM. 
		         
		        (5)bool loginsuper(char *x,int count)
		       	THIS FUNCTION IS FOR LOGGING IN OF A SUPERUSER ACCOUNT.
		       	
		       	(6)void superuser1(store*value)
		       	IT PERFORMS THE SUPEUSER FUNCTIONS.

----------------------------------------------------------------------------------------------------------------
                                             NGO MODULE------4TH TASK
       (NGO---NON.GOVERNMENT.ORGANISATION)
       
       
       
       SUB TASKS:
       a.JOINING IN THE GROUPS (B.I.N.G.O AND E.N.G.O): 
       -------->DESCRIPTION:
       		
       		ALREADY SOME USERS WILL JOIN IN EITHER OF THE GROUPS WHILE CREATING THEIR ACCOOUNTS. BUT SOME 				      	USERS WILL BE IN A DILEMMA TO JOIN IN WHICH GROUP SO THEY VISIT THE 						OFFICIAL   NGO OPTION AND JOIN IN B.I.N.G.O OR E.N.G.O GROUPS AND WE CAN 				VIEW THE UPDATED GROUP MEMBERS LIST...                           
                                             
       
       b.SOCIAL CAUSES:
       ---------> DESCRIPTION:
       		AS THE NAME NGO SUGGESTS THAT THEY SHOULD FORM SOME GROUPS AND REVOLT AGAINST THE 						PRESENT SOCIAL CAUSES SUCH AS POVERTY,FARMERS SUICIDE,CORRUPTION 					AND SOME ARTICLES ABOUT THESE CAUSES ARE WRITTEN IN THE NGO PAGE SO THE 					USERS WHO VISIT THIS OPTION AND WILL READ THE ARTICLE AND WILL GIVE 
       		(LIKES AND DISLIKES):                                    


	c.JUSTICE DONE TO USERS(DIFFERENT TYPE OF GRAPH)ADDITIONAL TASK:
	---------> DESCRIPTION:
		THIS IS ADDITIONAL TASK :
			AS THIS IS A SPECIAL TYPE OF GRAPH WHICH IS BASED ON THE FEEDBACK GIVEN BY THE USERS ON THE RESPECTIVE GOVERNMENT
			DEPARTMENTS SUCH AS MUNICIPALITY,HEALTH DEPARTMENT,TAX DEPARTMENT.
			RATING WILL BE GIVEN SO THIS GRAPH CONTAINS
				1.POOR PERFORMANCE
				2.AVERAGE PERFORMANCE
				3.GOOD PERFORMANCE
			SO THE USERS WILL GIVE THE FEEDBACK ON THE WORK DONE BY GOVT.OFFICIALS AND THE AVERAGE OF ALL COMPLAINTS IN 				THE RESPECTIVE DEPARTMENTS ARE TAKEN AND WILL BE PLOTTED IN THE FORM OF A GRAPH:
	EXAMPLE:
	MUNICIPALITY CONTAINS-->DOGS COMPLAINT,STREET LIGHTS ETC
	TAX DEPARTMENT CONTAINS---> OVER BLACK MONEY .
	HEALTH  CONTAIN -->IRREGULAR GIVING OF VACCINES TO PEOPLE
	
<------------->FUNCTIONS:
	
	void createnode()
		//CREATING FIRST NODE WHEN LIST IS EMPTY HEAD NODE FOR USER.TXT
	
	
	
	void insertnode()
		//CREATING LINKED LIST FOR USER.TXT 
	
	

	void createnode1()
		//CREATING FIRST NODE WHEN LIST IS EMPTY HEAD1 NODE FOR COMPLAINTS.TXT
	
	


	void insertnode1()
		//CREATING LINKED LIST FOR COMPLAINTS.TXT(SEPERATE FROM FIRST LINKED LIST)
	
	void convert()
		
	//CONVERTING AND EXTRACTING INFORMATION FROM THE FILES USER.TXT AND COMPLAINTS.TXT AND STORING IN THE 2D CHARACTER ARRAY AND PASSING 		IT
	

	void printlist()
		//PRINTING MEMBERS IN THE B.I.N.G.O OR E.N.G.O GROUPS UPDATED AND INITIAL MEMBERS ALSO
	
	



	void BINGO()

			//JOINING IN B.I.N.G.O GROUP AND SEEING THE UPDATED B.I.N.G.O GROUP MEMBERS AND EXIT ALSO(OPTIONAL)
	
	
	

	void ENGO()

		//JOINING IN E.N.G.O GROUP AND SEEING THE UPDATED E.N.G.O GROUP MEMBERS AND EXIT ALSO(OPTIONAL)
	


	void NGOgroup()
		//STORING THE MEMBERS IN THE RESPECTIVE GROUPS AND THOSE WHO OPTED NOTHING (WHO ARE IN DILEMMA) CAN JOIN IN THE GROUPS 
	
	
	void corruption()
	
		//ONE OF THE SOCIAL CAUSES (CORRUPTION), LIKES AND DISLIKES FOR THE MATTER GIVEN AND EXIT ALSO
	
	void poverty()
	
	
	//ONE OF THE SOCIAL CAUSES (POVERTY), LIKES AND DISLIKES FOR THE MATTER GIVEN AND EXIT ALSO
	
	void farmer()
	
	//ONE OF THE SOCIAL CAUSES (FARMER), LIKES AND DISLIKES FOR THE MATTER GIVEN AND EXIT ALSO

	


	void socialcauses()
	
	//MAIN FUNCTION FOR CALLING ABOVE FUNCTIONS 
	
	

	void graph()
	
		//(EXTRA TASK)PRINTING DIFFERENT TYPE OF GRAPH(PERFORMANCE DONE BY GOVERNMENT OFFICIALS ) --BASED ON THE FEEDBACK GIVEN BY 			THE USERS ON MUNICIPALITY,TAX DEPARTMENT,HEALTH

	


	void justice()

		//GETTING FEEDBACK OF DIFFERENT GOVT GROUPS 
	
	

	void NGO()
	
		//CALLING ALL THE 3 TASKS HERE
		MAIN WHEN WE OPEN TERMINAL 3 TASKS WILL BE DISPLAYED	
