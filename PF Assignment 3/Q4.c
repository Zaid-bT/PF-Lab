#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int** ratings, int numEmployees, int numPeriods){
	int i,j;
    for(i=0;i<numEmployees;i++){
        printf("Enter ratings for Employee %d:\n", i + 1);
        for(j=0;j<numPeriods;j++){
            int rating;
            do {
                printf("Enter rating for Period %d (1-10): ", j + 1);
                scanf("%d", &rating);
                if (rating < 1 || rating > 10) {
                    printf("Invalid rating! Rating must be between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            ratings[i][j] = rating;
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods){
	int i,j;
    printf("\nEmployee Performance Ratings:\n");
    for(i=0;i<numEmployees;i++){
        printf("Employee %d: ", i+1);
        for(j=0;j<numPeriods;j++){
            printf("%d ",ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
	int i,j;
    int bestEmployee = 0;
    float bestAverage =0.0;
    for(i=0;i<numEmployees;i++){
        float total = 0;
        for(j=0;j<numPeriods;j++){
            total += ratings[i][j];
        }
        float average = total / numPeriods;
        if (average > bestAverage) {
            bestAverage = average;
            bestEmployee = i;
        }
    }
    return bestEmployee;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods){
	int i,j;
    int bestPeriod = 0;
    float bestAverage = 0.0;
    for(j=0;j<numPeriods;j++){
        float total = 0;
        for(i=0;i<numEmployees;i++){
            total += ratings[i][j];
        }
        float average = total / numEmployees;
        if(average > bestAverage){
            bestAverage = average;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods){
	int i,j;
    int worstEmployee = 0;
    float worstAverage = 10.0;
    for(i=0;i<numEmployees;i++){
        float total = 0;
        for(j=0;j<numPeriods;j++){
            total += ratings[i][j];
        }
        float average = total / numPeriods;
        if(average < worstAverage){
            worstAverage = average;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}

int main(){
    int i,j,numEmployees,numPeriods;
    int employeeOfTheYear,highestRatedPeriod,worstEmployee;
    printf("Enter the number of employees: ");
    scanf("%d",&numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d",&numPeriods);
    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    for(i=0;i<numEmployees;i++){
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }
    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);
    employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year is Employee %d\n", employeeOfTheYear + 1);

    highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("The highest rated period is Period %d\n", highestRatedPeriod + 1);
    worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("The worst performing employee is Employee %d\n", worstEmployee + 1);

    for(i=0;i<numEmployees;i++){
        free(ratings[i]);
    }
    free(ratings);
    return 0;
}

