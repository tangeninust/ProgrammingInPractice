#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
#include "suppliers.h"
#include "assets.h"

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
        printf("8. Save Employees\n");
        printf("9. Load Employees\n");
        printf("10. Add Supplier\n");
        printf("11. List Suppliers\n");
        printf("12. Save Suppliers\n");
        printf("13. Load Suppliers\n");
        printf("14. Add Asset\n");
        printf("15. List Assets\n");
        printf("16. Save Assets\n");
        printf("17. Load Assets\n");
        printf("18. Save Budget\n");
        printf("19. Load Budget\n");
        printf("20. Exit\n");
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
            saveEmployees();
        }
        else if (choice == 9)
        {
            loadEmployees();
        }
        else if (choice == 10)
        {
            addSupplier();
        }
        else if (choice == 11)
        {
            listSuppliers();
        }
        else if (choice == 12)
        {
            saveSuppliers();
        }
        else if (choice == 13)
        {
            loadSuppliers();
        }
        else if (choice == 14)
        {
            addAsset();
        }
        else if (choice == 15)
        {
            listAssets();
        }
        else if (choice == 16)
        {
            saveAssets();
        }
        else if (choice == 17)
        {
            loadAssets();
        }
        else if (choice == 18)
        {
            saveBudget();
        }
        else if (choice == 19)
        {
            loadBudget();
        }
        else if (choice == 20)
        {
            printf("\nGoodbye.\n");
        }
        else
        {
            printf("\nInvalid choice.\n");
        }

    } while (choice != 20);

    return 0;
}