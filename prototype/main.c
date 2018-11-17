#include <stdlib.h>

#include "c_interface.h"
#include "c_class.h"

int main(void){
    CClass *o = cclass_ctor(42);
    c_use_interface((CInterface *)o);
    free(o);
}
