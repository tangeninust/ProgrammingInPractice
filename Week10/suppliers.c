#include <stdio.h>
#include <string.h>
#include "suppliers.h"

char supplierNames[10][50];
char supplierTowns[10][50];
int supplierCount = 0;

void addSupplier(void)
{
    if (supplierCount >= 10)
    {
        printf("\nSupplier list is full.\n");
        return;
    }

    printf("\nEnter supplier name: ");
    scanf("%49s", supplierNames[supplierCount]);

    printf("Enter supplier town: ");
    scanf("%49s", supplierTowns[supplierCount]);

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}

void listSuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added.\n");
        return;
    }

    printf("\n--- SUPPLIER LIST ---\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("Supplier %d: %s | Town: %s\n",
               i + 1,
               supplierNames[i],
               supplierTowns[i]);
    }
}

void saveSuppliers(void)
{
    FILE *fp = fopen("data/suppliers.txt", "w");

    if (fp == NULL)
    {
        perror("data/suppliers.txt");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        fprintf(fp, "%d|%s|%s\n",
                i + 1,
                supplierNames[i],
                supplierTowns[i]);
    }

    fclose(fp);

    printf("\nSuppliers saved successfully.\n");
}

void loadSuppliers(void)
{
    FILE *fp = fopen("data/suppliers.txt", "r");

    int id;
    char name[50];
    char town[50];

    if (fp == NULL)
    {
        perror("data/suppliers.txt");
        return;
    }

    supplierCount = 0;

    while (fscanf(fp, "%d|%49[^|]|%49[^\n]",
                  &id, name, town) == 3)
    {
        if (supplierCount < 10)
        {
            strcpy(supplierNames[supplierCount], name);
            strcpy(supplierTowns[supplierCount], town);
            supplierCount++;
        }
    }

    fclose(fp);

    printf("\nSuppliers loaded successfully.\n");
}