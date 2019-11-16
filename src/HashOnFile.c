#include "../include/HashOnFile.h"
#include "../include/Typedefs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Exception.h"

#define CHash(Obj, Hash) \
    if(Obj == NULL)                         \
    {                                       \
        throw(__NullPointerException__);    \
    }                                       \
    else                                    \
    {                                       \
        Hash = (HashTable)Obj;              \
    }
     


typedef struct HashTable
{
    FILE* hashPointers;
    FILE* data;
    unsigned elements;
    unsigned size;
    unsigned nextExpand;
    unsigned expandCounts;
    char* tag;
    int(*HashFunction)(Object key); 
}*HashTable;


Object newHashTable(const char* tag, int size, int(*HashFunction)(Object))
{
    HashTable hTable = NULL;
    unsigned i;
    int temp = -1;
    char *txt_file[20];

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
            hTable->HashFunction = HashFunction;
            if(hTable->tag != NULL)
            {
                strcpy(hTable->tag, tag);
            }
            else
            {
                throw(__MemoryAllocationException__);
            }

            strcat(txt_file, tag);
            strcat(txt_file,"_HashTable.bin");
            FileOpen(hTable->hashPointers, (const char*)txt_file, "wb+");
            memset(txt_file, 0, sizeof(txt_file));
            strcat(txt_file, tag);
            strcat(txt_file,"_Data.bin");
            FileOpen(hTable->data, (const char*)txt_file, "wb+");

            for(i = 0; i < (hTable->size+1); i++)
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

    return (Object)hTable;
}


void DestroyHashTable(Object hash)
{
    HashTable hTable = NULL;

    try
    {
        hTable = (HashTable)hash;

        if(hTable != NULL)
        {
            FileClose(hTable->hashPointers);
            //FileClose(hTable->data);
        }
        else
        {
            throw(__NullPointerException__);
        }
        
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }
}

void PrintHashTable(Object hash)
{
    HashTable hTable = NULL;
    unsigned i;
    int pointer = NULL_POINTER;
    char buff[32];

    try
    {
        hTable = (HashTable)hash;

        if(hTable != NULL)
        {	
        	ReWind(hTable->hashPointers);
            for(i = 0; i < hTable->size; i++)
            {
                FileRead(&pointer, sizeof(int), 1, hTable->hashPointers, int res);
                sprintf(buff, "%i", pointer);
                printf("%i\n", pointer);
                pointer = NULL_POINTER;
            }
        }
        else
        {
            throw(__NullPointerException__);
        }
        
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }
}

void InsertHashTable(Object hash, Object data, Object key)
{
    HashTable hTable = NULL;
    unsigned index;

    try
    {
        CHash(hash, hTable);
        ReWind(hTable->hashPointers);
        index = hTable->HashFunction(key);
        printf("index: %i\n", index);
        FileSeek(hTable->hashPointers, index * sizeof(int), SEEK_SET);
        FileWrite(&index, sizeof(unsigned int), 1, hTable->hashPointers, int res);
    }
    catch(NullPointerException)
    {
        PrintExceptionStdOut(NullPointerException);
    }
}