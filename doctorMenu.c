#include <stdio.h>
#include <stdlib.h>

void viewPatient();
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
    printf("1. View patient\n");
    printf("2. Exit\n\n");
    if(scanf(" %1[^\n]s", patientChoice) == -1){
    	printf("No input was found");
	}
    replace = strtol(patientChoice, &ptr, 10);
    switch (replace){
    case 1:{
        viewPatient();
        break;
    }
    case 2:{
        exit(0);
    }
    default:{
        printf("\n Invalid choice \n");
    }    
    } 

	}while(replace != 1 );
}

void viewPatient(){
    printf( "\n 5 \n" );

    patientMenu();
}

int main(){
    printf("Hello. Welcome to the program.\n");
    printf("Press RETURN key to continue...\n");
    if(getchar() == -1){
    	printf("No input was found");
	}
    patientMenu();

    return 0;

}


