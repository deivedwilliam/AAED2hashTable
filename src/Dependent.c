#include "../include/Dependent.h"
#include "../include/Exception.h"
#include "../include/Typedefs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 15U

typedef struct Dependent
{
	unsigned code;
	unsigned employee_code;
	char name[MAX_NAME];
	union 
	{
		struct 
		{
			unsigned age:7;
			unsigned next:24;
			unsigned status:1;
		};
	};
}*Dependent;

Object newDependent(unsigned code, unsigned employee_code, const char* name, short age)
{
	Dependent dpt = NULL;

	try
	{
		dpt = (Dependent)malloc(sizeof(struct Dependent));
		if(dpt != NULL)
		{
			dpt->code = code;
			dpt->employee_code = employee_code;
			strcpy(dpt->name, name);
			dpt->age = age;
			dpt->status = 1;
			dpt->next = -1;
		}
		else
		{
			throw(__MemoryAllocationException__);
		}
		
	}
	catch(MemoryAllocationException)
	{
		PrintExceptionStdOut(MemoryAllocationException);
	}

	return (Object)dpt;
}


const char* GetNameDependent(Object dependent)
{

}

short GetAgeDependent(Object dependent)
{

}

float GetEmployeeCode(Object dependent)
{

}