#include <stdio.h>
#include <string.h>

void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basicSalary, float allowance, float tax);
float calculateBudget(float revenue, float expenses);
void searchEmployee(char employees[5][50], int count);

int main()
{
    char employees[5][50] = {
        "Kleopas",
        "Tangeni",
        "Alberth",
        "Mbeha",
        "Nawa"
    };

    int choice;
    float amount;
    float basicSalary;
    float allowance;
    float tax;
    float revenue;
    float expenses;

    do
    {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter basic salary: ");
            scanf("%f", &basicSalary);

            printf("Enter allowance: ");
            scanf("%f", &allowance);

            printf("Enter tax: ");
            scanf("%f", &tax);

            printf("Net Salary: %.2f\n",
                   calculateSalary(basicSalary, allowance, tax));
        }
        else if (choice == 2)
        {
            printf("\nEnter amount: ");
            scanf("%f", &amount);

            printf("VAT: %.2f\n", calculateVAT(amount));
        }
        else if (choice == 3)
        {
            printf("\nEnter total revenue: ");
            scanf("%f", &revenue);

            printf("Enter total expenses: ");
            scanf("%f", &expenses);

            printf("Budget Balance: %.2f\n",
                   calculateBudget(revenue, expenses));
        }
        else if (choice == 4)
        {
            searchEmployee(employees, 5);
        }
        else if (choice == 5)
        {
            printf("\nSupplier Management will be handled in the MFMS module.\n");
        }
        else if (choice == 6)
        {
            printf("\nGoodbye.\n");
        }
        else
        {
            printf("\nInvalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

void displayMenu()
{
    printf("\n================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basicSalary, float allowance, float tax)
{
    float grossSalary;
    float netSalary;

    grossSalary = basicSalary + allowance;
    netSalary = grossSalary - tax;

    return netSalary;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void searchEmployee(char employees[5][50], int count)
{
    char searchName[50];
    int found = 0;

    printf("\nEnter employee name to search: ");
    scanf("%49s", searchName);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(employees[i], searchName) == 0)
        {
            printf("Employee found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Employee not found.\n");
    }
}