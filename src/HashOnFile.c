#include "../include/HashOnFile.h"
#include "../include/Typedefs.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/Exception.h"

#define NULL_POINTER -1

typedef struct HashTable
{
    FILE* hashPointers;
    unsigned elements;
    unsigned size;
    unsigned nextExpand;
    unsigned expandCounts;
    char* tag;
    int(*HashFunction)(Object hash, Object key); 
}*HashTable;


Hash newHashTable(const char* tag, int size)
{
    HashTable hTable = NULL;
    unsigned i;
    int temp = NULL_POINTER;

    try
    {
        hTable = (HashTable)malloc(sizeof(struct HashTable));
        memset(hTable, 0x000000000000000000, sizeof(struct HashTable));
        if(hTable != NULL)
        {

            hTable->size = size;
            hTable->nextExpand = 0;
            hTable->expandCounts = 0;
            hTable->tag = (char*)calloc(strlen(tag) + 1, sizeof(char));
            
            if(hTable->tag != NULL)
            {
                strcpy(hTable->tag, tag);
            }
            else
            {
                throw(__MemoryAllocationException__);
            }

            FileOpen(hTable->hashPointers, strcat(hTable->tag, "_hashTable.bin"), "w+b");

            for(i = 0; i < hTable->size; i++)
            {
                FileWrite(&temp , sizeof(unsigned), 1, hTable->hashPointers, int res);
            }
            
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

    return (Hash)hTable;
}