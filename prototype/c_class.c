#include "c_class.h"

#include <stdlib.h>
#include <stdio.h>


// "virtual" functions of CClass:

static void cclass_foo(CInterface *self){
  CClass *s = (CClass *)self;
  printf("foo: %d\n", s->val);
}

static int cclass_bar(CInterface *self, int input){
  CClass *s = (CClass *)self;
  return s->val*input;
}

static void cclass_dtor(CInterface *self){
  CClass *s= (CClass *)self;
  printf("deleting cclas-object with value %d\n", s->val);
}

// virtual table for CClass objects, shared between all objects:
static const CInterfaceVT cclass_vt = {&cclass_foo, &cclass_bar, &cclass_dtor};


// factory function, i.e. constructor
struct CClass *cclass_ctor(int val){
    CClass *o = (CClass *)malloc(sizeof(CClass));
    o->head.vt=&cclass_vt;
    o->val=val;
}

