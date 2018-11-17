#include "cpp_interface.h"

#include <iostream>

void use_interface(Interface &obj){
  std::cout<<"calling foo:"<<std::endl;
  obj.foo();
  std::cout<<"bar(42)="<<obj.bar(42)<<std::endl;
}
