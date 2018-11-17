#pragma once

/* 
*
*       C-API of the library
*
* This header is used by both, C++ and C
*
*/


#ifdef __cplusplus
extern "C" {
#endif

// Data structures needed to emulate virtual interfaces
// with pure C without C++-compiler support


// Head of all structs which represent the data
// of subclasses/substructs
typedef struct CInterfaceVT CInterfaceVT;
typedef struct CInterface{
    const CInterfaceVT *vt;
} CInterface;

// VTable (the actual interface)
struct CInterfaceVT{
    void(*foo)(CInterface *);
    int(*bar)(CInterface *, int);
    void(*dtor)(CInterface *);
};

// C-API wrapper of C++-functionality
void c_use_interface(CInterface *o);

#ifdef __cplusplus
}
#endif


