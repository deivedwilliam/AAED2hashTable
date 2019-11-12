#ifndef HASH_H_
#define HASH_H_

#include "../include/Typedefs.h"
#include <stdio.h>


Object newHashTable(const char* tag, int size, int(*HashFunction)(Object));

void InsertHashTable(Object hash, Object data, Object key);
void DestroyHashTable(Object hash);
void PrintHashTable(Object hash);

#endif