#include <stdio.h>
#include <stdlib.h>

#include "../include/HashOnFile.h"



int main(int argc, char const *argv[])
{
    Hash myHashTable;

    myHashTable = newHashTable("1234", 7u);

    return 0;
}
