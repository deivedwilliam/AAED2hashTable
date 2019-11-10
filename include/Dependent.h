#ifndef DEPENDENT_H_
#define DEPENDENT_H_


#include "../include/Typedefs.h"


Object newDependent(unsigned code, unsigned employee_code, const char* name, short age);


const char* GetNameDependent(Object dependent);
short GetAgeDependent(Object dependent);
float GetEmployeeCode(Object dependent);



#endif