#include <stdio.h>
#include <stdlib.h>

char loginUser(){
	
	const int MAXNAMELENGTH = 12;  //length for the username and password
	char username[MAXNAMELENGTH]; //will hold the username after found and separated
	const int MAXPWLENGTH = 12;
	char password[MAXPWLENGTH];  //same with password
	
	char authenticated = 'n';    //toggles to y if the username and password match an actual user
	char quit = 'n';
	char answer[1];
	char userType;				//user type will be read from the file after successful login, and is what is returned by this function
	char *tokenUN;				//a pointer to the token of the fget location of the file's text
	char *tokenPW;
	
	int triesRemaining = 10;
	
	const char d = '$';   //delimiter to separate username, password, and user type
	FILE *f;				//points to the file stream
	
	f = fopen("c:\Users\danp9\desktop\userlist.txt");   //creates the file stream
	
	//this is the main login loop, allows the user to try again
	do{
		
		printf("Please enter your login information.\nUsername:\n");
		scanf("%12[^\n]", username);			//scans the input from the command line, only reads the first 12 characters, delimited by a new line
		printf("Password\n");
		scanf("%12[^\n]", password);
	
		if(f != NULL){
		
			char userLoginInfo[26];   //stores each line of the user file, fgets is delimited by newline, and stores each input here
		
			while(fgets(userLoginInfo[26], sizeof(userLoginInfo), f) != NULL && authenticated != 'y'){
				tokenUN = strtok(userLoginInfo, p);  //reads to the first delimiter, should be the username
				tokenPW = strtok(NULL, p);
				
				if(&tokenUN.strcmp(username) && &tokenPW.strcmp(password){
					
					printf("Access Granted\n");
					
					userType = &strtok(NULL, p)[0];
					authenticated = 'y';
				}
			}
			if(authenticated = 'n'){
				triesRemaining--;
				printf("Username or Password was incorrect, tries remaining: %d\n", triesRemaining);
				
				while(quit != 'y' && quit != 'Y' && quit != 'n' && quit != 'N'){
					printf("do you wish to try again?(y/n)");
					scanf("%1[^\n]s", answer);   		//lets the user type as much as they want until they hit enter
														//and truncates it to one char and puts it in a char variable
					quit = answer[0];
				}
			}
		}
		else{
			printf("Cannot find critical data file, closing program...");
			return 0;
		}
	
	}while(authenticated == 'n' && quit == 'n');
	
	if(authenticated = 'y'){
		return userType;
	}
	else{
		return NULL;
	}
}

