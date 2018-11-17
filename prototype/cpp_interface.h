#pragma once

/* 
*
*     CPP-API of the library
*
* This header is used only by C++
*
*/


//some pure cpp-interface
class Interface{
public:
    virtual void foo() = 0;
    virtual int bar(int) = 0;
    virtual ~Interface() = default;
};

//functionality using cpp-interface
void use_interface(Interface &obj);

