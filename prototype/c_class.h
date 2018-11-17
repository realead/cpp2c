#pragma once

/* 
*
*   A consumer of the C-API
*
*/

// accesses only the C-API of the library:
#include "c_interface.h"

typedef struct CClass{
    CInterface head;  // inherits/implements CInterface
    int val;          // additional class-specific data
} CClass;


// factory function = constructor
//    allocates memory, sets right VT 
//    and initializes class-specific data
CClass *cclass_ctor(int val);

