#include <stdio.h>
#include <stdlib.h>

#include "../include/Employee.h"



int main(int argc, char const *argv[])
{
    Object empl = NULL;
    char* name;

   // empl = newEmployee(100, "Deived William", 25, 50000.89f);
    name = GetNameEmployee(empl);
  
    printf("%s ", name);

    return 0;
}
