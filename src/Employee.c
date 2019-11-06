#include "../include/Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/Exception.h"
#include <string.h>

#define CEmployee(Obj, Emp) \
    if(Obj == NULL)                         \
    {                                       \
        throw(__NullPointerException__);    \
    }                                       \
    else                                    \
    {                                       \
        Emp = (Employee)Obj;                \
    }
     


typedef struct Employee
{
    unsigned code;
    char* name;
    float salary;
    short age;
}*Employee;




Object newEmployee(unsigned code, const char* name, short age, float salary)
{
    Employee empl = NULL;

    try
    {
        empl = (Employee)malloc(sizeof(struct Employee));
        memset(empl, 0, sizeof(struct Employee));

        if(empl != NULL)
        {
            empl->code = code;
            empl->age = age;
            empl->name = (char*)calloc(strlen(name) + 1, sizeof(char));
            if(empl->name != NULL)
            {
                strcpy(empl->name, name);
            }
            else
            {
                throw(__MemoryAllocationException__);
            }
        }
        else
        {
            throw(__MemoryAllocationException__);
        }
    }catch(MemoryAllocationException)
    {
        PrintExceptionStdOut(MemoryAllocationException);
    }

    return empl;
}

const char* GetNameEmployee(Object employee)
{
    Employee emp;
    char* name = NULL;


    try
    {
        CEmployee(employee, emp);

        name = (char*)calloc(strlen(emp->name) + 1, sizeof(char));
        if(name != NULL)
        {
            strcpy(name, emp->name);
        }
        else
        {
            throw(__MemoryAllocationException__);
        }
        
        
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }
    catch(MemoryAllocationException)
    {
        PrintExceptionStdOut(MemoryAllocationException);
    }

    return name;
}
short GetAgeEmployee(Object employee)
{

}
float GetSalaryEmployee(Object employee)
{

}