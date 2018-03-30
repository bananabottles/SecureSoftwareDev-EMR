#include <stdio.h>
#include <stdlib.h>

void createUser();
void updateUser();
void deleteUser();
void viewLogs();



void patientMenu(void){
    char patientChoice[1];
    int replace;
    char *ptr;

do{

    printf("Menu 1\n");
    printf("~~~~~~~~~~\n");
    printf("1. Create User Account\n");
    printf("2. Update User Account\n");
    printf("3. Delete User Account\n");
    printf("4. View logs\n");
    printf("5. Exit\n\n");
    if(scanf(" %1[^\n]s", patientChoice) == -1){
    	printf("No input was found");
	}
    replace = strtol(patientChoice, &ptr, 10);
    switch (replace){
    case 1:{
        createUser();
        break;
    }
    case 2:{
        updateUser();
        break;
    }
    case 3:{
        deleteUser();
        break;
    }
    case 4:{
        viewLogs();
        break;
    }
    case 5:{
        exit(0);
    }
    default:{
        printf("\n Invalid choice \n");
    }    
    } 

	}while(replace != 1 && replace != 2 && replace != 3 && replace != 4);
}

void createUser(){
    printf( "\n 5 \n" );

    patientMenu();
}

void updateUser(){
    printf( "\n 4 \n" );

    patientMenu();	
}

void deleteUser(){
    printf( "\n 3 \n" );

    patientMenu();	
}

void viewLogs(){
    printf( "\n 2 \n" );

    patientMenu();	
}

int main(void){
    printf("Hello. Welcome to the program.\n");
    printf("Press RETURN key to continue...\n");
    if(getchar() == -1){
    	printf("No input was found");
	}
    patientMenu();

    return 0;

}
