#include<stdio.h>
#include<stdlib.h>

#include<login.h>


int main(){
	
	printf("Welcome to the Electronic Medical Record (EMR) System!\n");
	char userType;  //the login function will return the user type so the user will be redirected to the correct menu
	char shutdown;  //the menu functions could return a yes or no shutdown signal
						//yes would exit the loop and end the program, no would basically just sign out
						//which would loop back to the login screen
	do{
		shutdown = 'y';
		userType = NULL;
		
		userType = login();  //sends the user to the login screen and awaits the outcome
	
		if(userType != NULL){
			switch(userType){
				case 'a':
					//go to admin menu   shutdown = adminMenu();
					break;
				case 'e':
					//go to EP menu    shutdown = epMenu();
					break;
				case 'p':
					//go to patient menu	shutdown = patientMenu();
					break;
				default:
					printf("Error redirecting after login, terminating program...");
					return 0;
			}
		}
	}while(shutdown != 'y');
	return 0;
}
