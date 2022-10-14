/*successful
    x86-64 gcc 4.1-12.0.1 -O1
    x86-64 clang 3.0.0-14.0.0 -O1
    Compile and run the executable file，input 2147483647. If the output is "ok", then check "if (a + 10 > a)" is removed and there is a bug.
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