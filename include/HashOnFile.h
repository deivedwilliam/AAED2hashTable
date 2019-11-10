#ifndef HASH_H_
#define HASH_H_

#include "../include/Typedefs.h"
#include <stdio.h>

typedef void* Hash;


Hash newHashTable(const char* tag, int size);



#endif