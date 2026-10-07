#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    printf("\n--- EMPLOYEE REPORT ---\n");
    listEmployees();
}

void budgetReport(void)
{
    printf("\n--- BUDGET REPORT ---\n");
    printf("Budget Balance: %.2f\n", calculateBudgetBalance());
}