#include <stdio.h>
#include <string.h>
#include <time.h>

struct Employee{
    int employeeCode;
    char employeeName[100];
    struct tm dateOfJoining;
};

void EmployeeDetails(struct Employee* emp){
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode);
    getchar();

    printf("Enter employee name: ");
    fgets(emp->employeeName, sizeof(emp->employeeName), stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0';

    printf("Enter date of joining (DD MM YYYY): ");
    scanf("%d %d %d", &emp->dateOfJoining.tm_mday, &emp->dateOfJoining.tm_mon, &emp->dateOfJoining.tm_year);
    emp->dateOfJoining.tm_mon -= 1;
    emp->dateOfJoining.tm_year -= 1900;
}

void TenureDisplay(struct Employee employees[], int numEmployees){
	int i,years;
	time_t currentTime = time(NULL);
    struct tm currentDate = *localtime(&currentTime);
    int count3yrs = 0;
    printf("\nEmployees with tenure greater than 3 years:\n");
    for(i=0;i<numEmployees;i++){
        years=currentDate.tm_year - employees[i].dateOfJoining.tm_year;
        if(currentDate.tm_mon<employees[i].dateOfJoining.tm_mon || 
            (currentDate.tm_mon == employees[i].dateOfJoining.tm_mon && currentDate.tm_mday < employees[i].dateOfJoining.tm_mday)){
            years--;
        }
        if(years > 3){
            printf("\nEmployee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %02d/%02d/%d\n", employees[i].dateOfJoining.tm_mday,
                employees[i].dateOfJoining.tm_mon + 1, employees[i].dateOfJoining.tm_year + 1900);
            printf("Tenure: %d years\n", years);
            count3yrs++;
        }
    }
    printf("\nTotal employees with tenure greater than 3 years: %d\n", count3yrs);
}

int main(){
	int i;
    struct Employee employees[4];
    for(i=0;i<4;i++){
        printf("\nEnter details for employee %d:\n", i + 1);
        EmployeeDetails(&employees[i]);
    }
    TenureDisplay(employees, 4);
    return 0;
}

