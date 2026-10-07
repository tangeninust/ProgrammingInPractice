#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Add Budget\n");
        printf("5. Calculate Budget Balance\n");
        printf("6. Employee Report\n");
        printf("7. Budget Report\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            addEmployee();
        }
        else if (choice == 2)
        {
            listEmployees();
        }
        else if (choice == 3)
        {
            searchEmployee();
        }
        else if (choice == 4)
        {
            addBudget();
        }
        else if (choice == 5)
        {
            printf("Budget Balance: %.2f\n",
                   calculateBudgetBalance());
        }
        else if (choice == 6)
        {
            employeeReport();
        }
        else if (choice == 7)
        {
            budgetReport();
        }
        else if (choice == 8)
        {
            printf("\nGoodbye.\n");
        }
        else
        {
            printf("\nInvalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}

