# PAP521S – Programming in Practice

This week is on file handling and data persistence.

### Project

Municipal Financial Management System (MFMS)

### Objective

The multi-file MFMS project of Week 9 was extended to include file handling and data persistence in this Week 10 project.

### Text File Handling

Text files are used for saving and loading in the system:

* Employees – `data/employees.txt`
* Suppliers – `data/suppliers.txt`
* Assets – `data/assets.txt`
* Budgets – `data/budgets.txt`

The program uses:

The `fopen()` function is used to open a file.

The `fprintf()` function is used to write records.

The `fscanf()` function is used to read records.

The `fclose()` function is used to close files.

`perror()` and `NULL` checks are used to check for errors in files.

### Binary File Handling

In `binary.c` there is a demonstration of binary files.

The program uses:

The `fwrite()` function is used to write an employee record.

The `fread()` function is used to read the employee record.

The binary file is called `employees.dat`.

The binary file was successfully tested using an employee record that includes an ID, name and salary.

### Testing

These persistence tests were passed:

1. Employee data was successfully saved and loaded.
2. Supplier data was stored and loaded properly.
3. Asset data was saved and loaded successfully.
4. Budget data was successfully saved and loaded.
5. Binary employee data was successfully written and read.
6. The entire MFMS was compiled and linked successfully.
7. The program was reopened and the saved data was restored.

### Compilation

All the modules designed for MFMS were compiled separately and then linked:

```text
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc -std=c99 -Wall -Wextra -pedantic -c suppliers.c
gcc -std=c99 -Wall -Wextra -pedantic -c assets.c

gcc main.o employees.o budget.o utilities.o reports.o suppliers.o assets.o -o mfms
```

### Files

These are the primary source files, header files, data directory and binary demonstration for Week 10.

### Conclusion

The concepts of text file handling, binary file handling and persistence of municipal management data are successfully implemented in the Week 10 MFMS.
