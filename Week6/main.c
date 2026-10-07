#include <stdio.h>
#include <string.h>

int main()
{
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;

    float searchSalary;
    int salaryFound = 0;

    float totalBudget = 0;
    float averageBudget;
    float temp;

    char searchRegistration[20];
    int registrationFound = 0;

    /* EMPLOYEE SALARIES */

    printf("MUNICIPAL EMPLOYEE SALARY MANAGEMENT\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary = totalSalary + salaries[i];
    }

    highestSalary = salaries[0];
    lowestSalary = salaries[0];

    for (int i = 1; i < 50; i++)
    {
        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    printf("\n--- Employee Salaries ---\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    printf("\n--- Salary Report ---\n");
    printf("Total salary expenditure: %.2f\n", totalSalary);
    printf("Average salary: %.2f\n", averageSalary);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary: %.2f\n", lowestSalary);

    /* SEARCH FOR SALARY */

    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary found at employee %d.\n", i + 1);
            salaryFound = 1;
            break;
        }
    }

    if (!salaryFound)
    {
        printf("Salary not found.\n");
    }

    /* DEPARTMENT BUDGETS */

    printf("\nMUNICIPAL DEPARTMENT BUDGETS\n");
    printf("----------------------------\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);

        totalBudget = totalBudget + budgets[i];
    }

    averageBudget = totalBudget / 10;

    printf("\n--- Department Budgets ---\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    printf("\nTotal budget: %.2f\n", totalBudget);
    printf("Average budget: %.2f\n", averageBudget);

    /* SORT BUDGETS */

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted from Lowest to Highest ---\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    /* VEHICLE REGISTRATION NUMBERS */

    printf("\nMUNICIPAL VEHICLE REGISTRATIONS\n");
    printf("-------------------------------\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\n--- Vehicle Registrations ---\n");

    for (int i = 0; i < 20; i++)
    {
        printf("%s\n", registrations[i]);
    }

    /* SEARCH FOR VEHICLE REGISTRATION */

    printf("\nEnter vehicle registration to search for: ");
    scanf("%19s", searchRegistration);

    for (int i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i], searchRegistration) == 0)
        {
            printf("Registration found at position %d.\n", i + 1);
            registrationFound = 1;
            break;
        }
    }

    if (!registrationFound)
    {
        printf("Registration not found.\n");
    }

    return 0;
}