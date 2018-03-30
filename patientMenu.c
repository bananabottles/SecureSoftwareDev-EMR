#include <stdio.h>
#include <stdlib.h>

void viewAppointment();
void viewPrescription();
void priorRecord();
void patientMenu();


void patientMenu(){
    char patientChoice[1];
    int replace;
    char *ptr;
do{

    printf("Menu 1\n");
    printf("~~~~~~~~~~\n");
    printf("1. View appointments\n");
    printf("2. View prescriptions\n");
    printf("3. Prior records\n");
    printf("4. Exit\n\n");
    if(scanf(" %1[^\n]s", patientChoice) == -1){
    	printf("No input was found");
	}
    replace = strtol(patientChoice, &ptr, 10);
    switch (replace){
    case 1:{
        viewAppointment();
        break;
    }
    case 2:{
        viewPrescription();
        break;
    }
    case 3:{
        priorRecord();
        break;
    }
    case 4:{
        exit(0);
    }
    default:{
        printf("\n Invalid choice \n");
    }    
    } 

	}while(replace != 1 && replace != 2 && replace != 3);
}

void viewAppointment(){
    printf( "\n 5 \n" );

    patientMenu();
}

void viewPrescription(){
    printf( "\n 4 \n" );

    patientMenu();	
}

void priorRecord(){
    printf( "\n 3 \n" );

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

