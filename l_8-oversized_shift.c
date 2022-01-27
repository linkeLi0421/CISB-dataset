/*successful
    X86-64 gcc 4.1.2-10.1 -O2
    x86-64 clang 3.0.0-11.0.0 -O2
    arm gcc 4.5.4-9.2.1 -O2
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
    int size;
    //input 32
    size = atoi(argv[1]);
    int g = 0;
    g = 1 << size;
    if (g == 0 || g == 1)
        printf("%d\n", g);
    return 0;
}