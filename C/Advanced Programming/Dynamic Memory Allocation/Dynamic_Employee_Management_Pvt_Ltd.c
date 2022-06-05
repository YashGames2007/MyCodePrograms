#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! ABC Employee Management System Pvt. Ltd.
typedef struct Dynamic_Employee_Management_Pvt_Ltd
{
    char *employee_ID;
} employee;

employee *get_Details();
void present_Details(employee *employees, int total_Employees);
void clear(void);

int main()
{
    int *total = (int *)malloc(sizeof(int));
    
    printf("\nEnter The Total Number of Employees: ");
    scanf("%d", total);

    const int total_Employees = *total;
    free(total);
    // printf("\nTotal: %d", total_Employees);
    employee *employees = (employee *)malloc(total_Employees * sizeof(employee));

    for (int i = 0; i < total_Employees; i++)
    {
        printf("\nScanning Details of Employee No. %d ...", i + 1);
        employees[i] = *get_Details();
    }
    present_Details(employees, total_Employees);

    // employees = realloc(employees, 0);
    for (int i = 0; i < total_Employees; i++)
    {
        free(employees[i].employee_ID);
    }
    free(employees);

    return 0;
} 
employee *get_Details()
{
    employee *new_Employee = (employee *)malloc(sizeof(employee));
    int size_ID;

    printf("\n\nEnter The Number of Characters In Your Emp. ID: ");
    scanf("%d", &size_ID);

    char emp_ID[size_ID + 1];
    new_Employee -> employee_ID = (char *)malloc((size_ID + 1) * sizeof(char));

    printf("\n\nEnter Your Employee ID: ");
    clear();
    gets(emp_ID);

    strcpy(new_Employee -> employee_ID, emp_ID);
    return new_Employee;
}
void present_Details(employee *employees, int total_Employees)
{
    printf("\n\nPrinting Employee Details: \n");
    for (int i = 0; i < total_Employees; i++)
    {
        printf("\n\nEmployee No.%d :", i + 1);
        printf("\n\tEmployee ID: %s", employees[i].employee_ID);
    }
}
extern void clear(void)
{
    while (getchar() != '\n');
}