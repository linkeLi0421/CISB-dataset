/*successful
    x86-64 gcc 4.8.5 -O2
    x86-64 clang 3.0.0-trunk -O1
*/
int test(int a) {
    if (a + 10 > a) {   // removed
        printf("ok");
    }
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    int a = atoi(argv[1]);//input 0x7fffffff(2147483647)
    test(a);
    return 0;
}