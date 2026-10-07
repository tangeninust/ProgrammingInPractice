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

void saveBudget(void)
{
    FILE *fp = fopen("data/budgets.txt", "w");

    if (fp == NULL)
    {
        perror("data/budgets.txt");
        return;
    }

    fprintf(fp, "%.2f|%.2f\n", revenue, expenses);

    fclose(fp);

    printf("\nBudget saved successfully.\n");
}

void loadBudget(void)
{
    FILE *fp = fopen("data/budgets.txt", "r");

    if (fp == NULL)
    {
        perror("data/budgets.txt");
        return;
    }

    if (fscanf(fp, "%lf|%lf", &revenue, &expenses) == 2)
    {
        printf("\nBudget loaded successfully.\n");
    }
    else
    {
        printf("\nUnable to read budget data.\n");
    }

    fclose(fp);
}