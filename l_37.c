/*
	x86-64gcc 4.5-11.2 -O2
	x86-64clang 3.0.0-14.0.0 -O1
	Compile and generate the disassembly code of this program, if section "<main>:" doesn't contain "sub", there is a bug.
*/

#include <stdio.h>
#include <time.h>

int main(){
    int i;
    for (i=0;i<=0x7ffffff;i++);
    return 0;
}