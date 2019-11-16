#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_


#include "../include/Typedefs.h"



Object newEmployee(unsigned code, const char* name, short age, float salary);

const char* GetNameEmployee(Object employee);
int GetAgeEmployee(Object employee);
unsigned GetCodeEmployee(Object employee);
float GetSalaryEmployee(Object employee);
void FreeEmployee(Object employee);
int GetNextPointer(Object employee);
int GetStatusFlag(Object employee);
void FreeStatusFlag(Object employee);
long int getRegisterSize(void);
void PrintEmployee(Object reg);

#endif