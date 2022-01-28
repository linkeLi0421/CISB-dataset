/*
	successful 
	x86-64 gcc7.1-11.2 -O2
	x86-64 clang5.0.0-13.0.0 -O1
	
*/

#include <stdio.h>
#include <string.h>

unsigned int a[100];

int main(int argc, char** argv) {
    char* a;
    char* b;
    a = argv[1];
    b = argv[2];
    if(memcmp(a, b, 10) != 0){
        printf("ok");
    }
    return 0;
}
