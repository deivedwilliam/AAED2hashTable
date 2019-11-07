#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_


#include "../include/Typedefs.h"



Object newEmployee(unsigned code, const char* name, short age, float salary);

const char* GetNameEmployee(Object employee);
short GetAgeEmployee(Object employee);
float GetSalaryEmployee(Object employee);
void FreeEmployee(Object employee);



#endif