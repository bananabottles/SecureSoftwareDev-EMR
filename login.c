#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "login.h"

char loginUser(void){
	
	const int MAXNAMELENGTH = 12;  //length for the username and password
	char username[MAXNAMELENGTH]; //will hold the username after found and separated
	const int MAXPWLENGTH = 12;
	char password[MAXPWLENGTH];  //same with password
	
	char authenticated;    //toggles to y if the username and password match an actual user
	char quit;
	char answer[1];
	char userType;				//user type will be read from the file after successful login, and is what is returned by this function
	
	char un[14];
	char pw[14];
	
	/*
	char *tokenUN;				//a pointer to the token of the fgets location of the file's text
	char *tokenPW;
	char *tokenUT;  //user type token
	char un[12];
	char pw[12];
	char ut;
	char *tokens[3];
	*/
	int triesRemaining = 10;
	
	const char d[1] = "$";   //delimiter to separate username, password, and user type
	FILE *f;				//points to the file stream
	
	f = fopen("userlist.txt", "r");   //creates the file stream
	
	//this is the main login loop, allows the user to try again
	do{
		authenticated = 'n';
		quit = 'n';
		
		printf("Please enter your login information.\nUsername:\n");
		scanf(" %12[^\n]s", username);			//scans the input from the command line, only reads the first 12 characters, delimited by a new line
		printf("Password:\n");
		scanf(" %12[^\n]s", password);
		
	
		if(f != NULL){   //run this if the file exists
			

			char userLoginInfo[40];   //stores each line of the user file, fgets is delimited by newline, and stores each input here
		
			while(!feof(f) && authenticated == 'n'){    //gets each line of text from the file until it reaches the end of the file
			
				fgets(userLoginInfo, sizeof(userLoginInfo)-1, f);
				userLoginInfo[strcspn(userLoginInfo, "\n")] = '\0';
				
				printf("info \"%s\"\n", userLoginInfo);
				
				sscanf(userLoginInfo, "%[^$]$%[^$]$%c", un, pw, userType);
				
				
				/*
				tokenUN = strtok(userLoginInfo, d);  //reads to the first delimiter, should be the username
				printf("name \"%s\"\n", tokenUN);
				strncpy(un, tokenUN, strlen(tokenUN)-1);
				
				tokenPW = strtok(NULL, d);          //reads password
				printf("pass \"%s\"\n", tokenPW);
				strncpy(pw, tokenPW, strlen(tokenPW)-1);
				
				tokenUT = strtok(NULL, d);
				printf("type \"%s\"\n", tokenUT);		//reads user type
				
				token = strtok(userLoginInfo, d);
				tokens[0] = token;
				*/
				
				printf("%s:%s   %s:%s   userType:%c\n", username, un, password, pw, userType);
				
				if(strcmp(username, un) == 0 && strcmp(password, pw) == 0){
					printf("Access Granted\n");

					printf("type after converted %c\n", userType);
					authenticated = 'y';		//exits the login loop with this character
				}
				
				printf("end of loop\n");
			}
			
		}
		else{  	//if the user file cant be found
			printf("Cannot find critical data file, closing program...");
			exit(0);
		}
		
		if(authenticated == 'n'){
			triesRemaining--;			//decrements the number of tries if the username or password is incorrect
			printf("Username or Password was incorrect, tries remaining: %d\n", triesRemaining);
			
			do{
				printf("do you wish to try again?(y/n)");
				scanf(" %1[^\n]s", answer);   		//lets the user type as much as they want until they hit enter
													//and truncates it to one char and puts it in a char variable
			}while(strcasecmp(answer, "y") && strcasecmp(answer, "n"));
			
			printf("%s\n", answer);
			//translates the answer string to the quit character signal
			if(strcasecmp(answer, "y") == 0){
				quit = 'n';
			}
			if(strcasecmp(answer, "n") == 0){
				quit = 'y';
			}
		}
	}while(authenticated == 'n' && quit == 'n' && triesRemaining > 0);	//loops the login cycle if the input was incorrect, the user wants to try again, and there are tries remaining
	
	if(authenticated == 'y'){
		return userType;
	}
	else{
		return 'q';
	}
	return 'q';
}

