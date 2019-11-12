#include "../include/Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include "../include/Exception.h"
#include <string.h>

#define MAX_NAME 15U

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
    char name[MAX_NAME];
    float salary;
    union 
	{
		struct 
		{
			unsigned next:24;
            unsigned age:7;
			unsigned status:1;
		};
	};
}*Employee;




Object newEmployee(unsigned code, const char* name, short age, float salary)
{
    Employee empl = NULL;

    try
    {
        empl = (Employee)malloc(sizeof(struct Employee));
                                                                                          
        if(empl != NULL)
        {
            empl->code = code;
            empl->age = age;
            empl->next = -1;
            empl->status = 1;
            strcpy(empl->name, name);
        }
        else
        {
            throw(__MemoryAllocationException__);
        }
    }catch(MemoryAllocationException)
    {
        PrintExceptionStdOut(MemoryAllocationException);
    }

    return (Object)empl;
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
int GetAgeEmployee(Object employee)
{
    Employee empl = NULL;
    int age = -1;

    try
    {
        CEmployee(employee, empl);
        age = empl->age;
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }

    return age;
}

float GetSalaryEmployee(Object employee)
{
    Employee empl = NULL;
    float salary = 0.0f;

    try
    {
        CEmployee(employee, empl);
        salary = empl->salary;
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }

    return salary;
}

int GetNextPointer(Object employee)
{
    Employee empl = NULL;
    int next = NULL_POINTER;

    try
    {
        CEmployee(employee, empl);
        next = (int)(short)(empl->next);
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }

    return next;
}

int GetStatusFlag(Object employee)
{
    Employee empl = NULL;
    int status = NULL_POINTER;

    try
    {
        CEmployee(employee, empl);
        status = (int)(empl->status);
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }

    return status;
}
void FreeEmployee(Object employee)
{
    Employee empl;

    try
    {
        CEmployee(employee, empl);
        free(empl->name);
        free(employee);
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }
}

unsigned GetCodeEmployee(Object employee)
{
    Employee empl = NULL;
    unsigned int code;

    try
    {
        CEmployee(employee, empl);
        code = empl->code;
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }

    return code;
}