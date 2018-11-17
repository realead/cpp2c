# compiling cpp-part
g++ -c -std=c++11 -fPIC cpp_interface.cpp -o cpp_interface.o
g++ -c -std=c++11 -fPIC c_interface.cpp -o c_interface.o
g++ --shared c_interface.o cpp_interface.o -o libCPP.so

#compiling c-part
gcc -std=c11 -c c_class.c -o c_class.o
gcc -std=c11 -c main.c -o main.o

gcc c_class.o main.o -L . -Wl,-rpath="." -l CPP -o prog
