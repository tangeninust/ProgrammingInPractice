#include <stdio.h>
#include <string.h>
#include "assets.h"

char assetNames[10][50];
float assetValues[10];
int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= 10)
    {
        printf("\nAsset list is full.\n");
        return;
    }

    printf("\nEnter asset name: ");
    scanf("%49s", assetNames[assetCount]);

    printf("Enter asset value: ");
    scanf("%f", &assetValues[assetCount]);

    assetCount++;

    printf("\nAsset added successfully.\n");
}

void listAssets(void)
{
    if (assetCount == 0)
    {
        printf("\nNo assets have been added.\n");
        return;
    }

    printf("\n--- ASSET LIST ---\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("Asset %d: %s | Value: %.2f\n",
               i + 1,
               assetNames[i],
               assetValues[i]);
    }
}

void saveAssets(void)
{
    FILE *fp = fopen("data/assets.txt", "w");

    if (fp == NULL)
    {
        perror("data/assets.txt");
        return;
    }

    for (int i = 0; i < assetCount; i++)
    {
        fprintf(fp, "%d|%s|%.2f\n",
                i + 1,
                assetNames[i],
                assetValues[i]);
    }

    fclose(fp);

    printf("\nAssets saved successfully.\n");
}

void loadAssets(void)
{
    FILE *fp = fopen("data/assets.txt", "r");

    int id;
    char name[50];
    float value;

    if (fp == NULL)
    {
        perror("data/assets.txt");
        return;
    }

    assetCount = 0;

    while (fscanf(fp, "%d|%49[^|]|%f",
                  &id, name, &value) == 3)
    {
        if (assetCount < 10)
        {
            strcpy(assetNames[assetCount], name);
            assetValues[assetCount] = value;
            assetCount++;
        }
    }

    fclose(fp);

    printf("\nAssets loaded successfully.\n");
}