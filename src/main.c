#include <stdio.h>
#include <stdlib.h>

#include "../include/HashOnFile.h"
#include "../include/Exception.h"
#include "../include/Employee.h"



int HashFunction(Object key)
{
    int index;

    index = (*(unsigned*)key) % 7;

    return index;
}

void ReadRegisterFile(Object file)
{
    FILE* f = file;
    int res;
    Object obj;

    obj = (Object)malloc(getRegisterSize());

    while(1)
    {
        puts("*************************************************");
        FileRead(obj, getRegisterSize(), 1, f, res);
        PrintEmployee(obj);
        puts("*************************************************");
        if(!feof(f))
            break;
    }
}

int main(int argc, char const *argv[])
{
    Object empl = NULL;
    unsigned code;
    Object myHashTable = newHashTable("1234", 7u, HashFunction);

    empl = newEmployee(100, "deived william", 25, 100785.89f);

    code = GetCodeEmployee(empl);

    InsertHashTable(myHashTable, empl, &code, getRegisterSize());

    PrintHashTable(myHashTable);

    PrintRegisterFile(myHashTable, ReadRegisterFile);

    DestroyHashTable(myHashTable);

  



    return 0;
}
