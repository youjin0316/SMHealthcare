//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

/*
coding flow
1. Read txt file and store it in the database-loadExercises,loadDiets
2. Backup the progress to the health_data.txt file-saveData
3. Allows the user to slelect desired number and save in health_data-inputExercise,inputDiets
4. Provide history and recommendations-printHealthData
5. do-while if(remaining_calories==0) error->if(0)
6. Find condition User eats three meals a day->if (remaining_calories==0&&health_data.diet_count>0)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH);
    loadDiets(DIETFILEPATH);
    
    int remaining_calories=(health_data.total_calories_intake-(BASAL_METABOLIC_RATE+health_data.total_calories_burned));

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    
    	
    	if (remaining_calories==0&&health_data.diet_count>0){// Condition: User eats three meals a day.
            printf("You have consumed all your calories for today! \n");
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	inputExercise(&health_data);
                break;
                
            case 2:
            	inputDiet(&health_data);
                break;
                
            case 3:
            	printHealthData(&health_data);
                break;
                
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
        saveData(HEALTHFILEPATH,&health_data);
    } while (choice!=4||remaining_calories!=0);//End condition

    return 0;
}

