#include <stdio.h>
#include <stdlib.h>

#include "../include/HashOnFile.h"
#include "../include/Employee.h"



int HashFunction(Object key)
{
    int index;

    index = (*(unsigned*)key) % 7;

    return index;
}

int main(int argc, char const *argv[])
{
    Object empl = NULL;
    unsigned code;
    Object myHashTable = newHashTable("1234", 7u, HashFunction);

    empl = newEmployee(100, "deived william", 25, 100785.89f);

    code = GetCodeEmployee(empl);

    InsertHashTable(myHashTable, empl, &code);

    PrintHashTable(myHashTable);

    DestroyHashTable(myHashTable);

  



    return 0;
}
