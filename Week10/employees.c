#include <stdio.h>
#include <string.h>
#include "employees.h"

char employeeNames[10][50];
float employeeSalaries[10];
int employeeCount = 0;

void addEmployee(void)
{
    if (employeeCount >= 10)
    {
        printf("\nEmployee list is full.\n");
        return;
    }

    printf("\nEnter employee name: ");
    scanf("%49s", employeeNames[employeeCount]);

    printf("Enter employee salary: ");
    scanf("%f", &employeeSalaries[employeeCount]);

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}

void listEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\nNo employees have been added.\n");
        return;
    }

    printf("\n--- EMPLOYEE LIST ---\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("Employee %d: %s | Salary: %.2f\n",
               i + 1,
               employeeNames[i],
               employeeSalaries[i]);
    }
}

void searchEmployee(void)
{
    char searchName[50];
    int found = 0;

    printf("\nEnter employee name to search: ");
    scanf("%49s", searchName);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employeeNames[i], searchName) == 0)
        {
            printf("\nEmployee found.\n");
            printf("Name: %s\n", employeeNames[i]);
            printf("Salary: %.2f\n", employeeSalaries[i]);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}

void saveEmployees(void)
{
    FILE *fp = fopen("data/employees.txt", "w");

    if (fp == NULL)
    {
        perror("data/employees.txt");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        fprintf(fp, "%d|%s|%.2f\n",
                i + 1,
                employeeNames[i],
                employeeSalaries[i]);
    }

    fclose(fp);

    printf("\nEmployees saved successfully.\n");
}

void loadEmployees(void)
{
    FILE *fp = fopen("data/employees.txt", "r");

    int id;
    char name[50];
    float salary;

    if (fp == NULL)
    {
        perror("data/employees.txt");
        return;
    }

    employeeCount = 0;

    while (fscanf(fp, "%d|%49[^|]|%f",
                  &id, name, &salary) == 3)
    {
        if (employeeCount < 10)
        {
            strcpy(employeeNames[employeeCount], name);
            employeeSalaries[employeeCount] = salary;
            employeeCount++;
        }
    }

    fclose(fp);

    printf("\nEmployees loaded successfully.\n");
}