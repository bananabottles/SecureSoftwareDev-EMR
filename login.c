#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



char loginUser(void){
	
	const int MAXNAMELENGTH = 14;  //length for the username and password
	char username[MAXNAMELENGTH]; //will hold the username after found and separated
	const int MAXPWLENGTH = 14;
	char password[MAXPWLENGTH];  //same with password
	
	char authenticated;    //toggles to y if the username and password match an actual user
	char quit;
	char answer;
	char userType;				//user type will be read from the file after successful login, and is what is returned by this function
	
	char un[MAXNAMELENGTH];    //used to store file data for comparison with user input
	char pw[MAXPWLENGTH];
	
	int triesRemaining = 5;
	
	const char d[1] = "$";   //delimiter to separate username, password, and user type
	FILE *f;				//points to the file stream
	
	f = fopen("user_list.txt", "r");   //creates the file stream
	
	//this is the main login loop, allows the user to try again
	do{
		
		f = fopen("user_list.txt", "r");   //creates the file stream
		
		authenticated = 'n';
		quit = 'y';
		
		printf("Please enter your login information.\nUsername:\n");
		scanf(" %12s", username);			//scans the input from the command line, only reads the first 12 characters, delimited by a new line
		while ((getchar()) != '\n');       //clears the input buffer from any extra possible inputs
		printf("Password:\n");
		scanf(" %12s", password);         
		while ((getchar()) != '\n');       //clears the input buffer from any extra possible inputs
		
	
		if(f != NULL){   //run this if the file exists
		
			char userLoginInfo[40];   //stores each line of the user file, fgets is delimited by newline, and stores each input here
		
			while(fgets(userLoginInfo, sizeof(userLoginInfo)-1, f) && authenticated == 'n'){    //gets each line of text from the file until it reaches the end of the file
			
				userLoginInfo[strcspn(userLoginInfo, "\n")] = '\0'; //removes the new line from the fgets string
				
				strcpy(userLoginInfo, userLoginInfo);    //turns the string pointer to a string
				
				sscanf(userLoginInfo, " %s %s %c", un, pw, &userType);   //separates the information from the file into variables
				
				//compares the user input with file data
				if(strcmp(username, un) == 0 && strcmp(password, pw) == 0){
					printf("Access Granted\n");
					authenticated = 'y';		//exits the login loop with this character
				}
			}
		}
		else{  	//if the user file cant be found
			printf("Cannot find critical data file, closing program...");
			exit(0);
		}
		
		if(authenticated == 'n' && triesRemaining > 1){
			triesRemaining--;			//decrements the number of tries if the username or password is incorrect
			printf("Username or Password was incorrect, tries remaining: %d\n", triesRemaining);
			
			do{
				printf("do you wish to try again?(y/n)");
				scanf(" %c", &answer);   		//gets one input from the user
				while ((getchar()) != '\n');    //clears the input buffer from any extra possible inputs
			}while(answer != 'y' && answer != 'n');

			//translates the answer string to the quit character signal
			if(answer == 'y'){
				quit = 'n';
			}
		}
	
		printf("closing file... ");
		fclose(f);
		printf("file closed\n");
		
	}while(authenticated == 'n' && quit == 'n');	//loops the login cycle if the input was incorrect, the user wants to try again, and there are tries remaining
	
	if(authenticated == 'y'){
		return userType;      //returns usertype to send the user to the correct menu from main
	}
	else{
		return 'q';  //returns q to quit the program in main
	}
	return 'q';
}
