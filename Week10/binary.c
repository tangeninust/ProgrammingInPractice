#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    double salary;
} Employee;

int main(void)
{
    Employee employee;

    employee.id = 1001;
    snprintf(employee.name, sizeof(employee.name), "Kleopas");
    employee.salary = 15000.00;

    FILE *fp = fopen("data/employees.dat", "wb");

    if (fp == NULL)
    {
        perror("data/employees.dat");
        return 1;
    }

    if (fwrite(&employee, sizeof employee, 1, fp) != 1)
    {
        perror("Error writing employee");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    fp = fopen("data/employees.dat", "rb");

    if (fp == NULL)
    {
        perror("data/employees.dat");
        return 1;
    }

    Employee loadedEmployee;

    if (fread(&loadedEmployee, sizeof loadedEmployee, 1, fp) == 1)
    {
        printf("Employee loaded from binary file:\n");
        printf("ID: %d\n", loadedEmployee.id);
        printf("Name: %s\n", loadedEmployee.name);
        printf("Salary: %.2f\n", loadedEmployee.salary);
    }
    else
    {
        printf("Unable to read employee data.\n");
    }

    fclose(fp);

    return 0;
}