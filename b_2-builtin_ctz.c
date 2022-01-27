/*successful
    x86-64 gcc 4.9.0-trunk -O2
    x86-64 clang 3.1.0-trunk -O1
*/
#include<stdio.h>

void test(int p){
    
    if(__builtin_ctz(p)>= 32){ // removed
		printf("ok");
	}

}

int main(int argc, char** argv){
    int a = atoi(argv[1]);
    //int a = 0;
    test(a);

}