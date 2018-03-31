#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include "login.c"


int main(void){
	
	printf("Welcome to the Electronic Medical Record (EMR) System!\n");
	char userType;  //the login function will return the user type so the user will be redirected to the correct menu
	char shutdown;  //the menu functions could return a yes or no shutdown signal
						//yes would exit the loop and end the program, no would basically just sign out
						//which would loop back to the login screen
	do{
		shutdown = 'y';
		userType = 'q'; //q is the quit signal that will eexit the login loop to shutdown
	
		userType = loginUser();  //sends the user to the login screen and awaits the outcome
	
		switch(userType){
			case 'a':
				printf("Redirecting to admin menu\n");
				//go to admin menu   shutdown = adminMenu();
				break;
			case 'd':
				printf("Redirecting to doctor menu\n");
				//go to doctor menu    shutdown = doctorMenu();
				break;
			case 'p':
				printf("Redirecting to patient menu\n");
				//go to patient menu	shutdown = patientMenu();
				break;
			case 'q':
				printf("Exiting program...");
				shutdown = 'y';
				break;
			default:
				printf("Error redirecting after login, terminating program...");
				shutdown = 'y';
				break;
		}
	}while(shutdown != 'y');
	return 0;
}
