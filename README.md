# cpp2c

A proof of concept for exposing C++-API with pure-interfaces to C-consumers preserving type safety.

## Motivation

Given some C++-API which contains some pure interfaces, for example 

    //some pure cpp-interface
    class Interface{
    public:
        virtual void foo() = 0;
        virtual int bar(int) = 0;
        virtual ~Interface() = default;
    };

    //functionality using cpp-interface
    void use_interface(Interface &obj);

we would like to use it from pure C-code. Yet because there are no virtual classes in C, we cannot use this functionality out-of-the-box.

## C-API wrapper

The prof of concept can be found in the `prototype`-folder and consist of the following part.

  1. Core C++-functionality (`prototype/cpp_interface.*`).
  2. C++-wrapper around the core-functionality exposing the core-functionality as C-API (`prototype/c_interface.*`).
  3. An example of a pure C-implementation of C++-interfaces wrapped in the above C-API.
  4. C-consumer of the above C-API (`prototype/main.c`).

### Idea

The C-API wrapper makes by hand, what C++-compiler would do automatically:

   1. use `struct` for aggregation of the data member of the mocked c++-class.
   2. first element of the above struct is a virtual table, which can be overwritted by the "derived" subclasses.
   3. An adapter wraps data-struct + vt into a c++-representation of the interface.

## Build/Run

Build the prototype in the `prototype`-folder via 
  
   sh build.sh

and run it via

  ./prog
