#include <stdio.h>
#include "budget.h"

double revenue = 0.0;
double expenses = 0.0;

void addBudget(void)
{
    printf("\nEnter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    printf("\nBudget added successfully.\n");
}

double calculateBudgetBalance(void)
{
    return revenue - expenses;
}