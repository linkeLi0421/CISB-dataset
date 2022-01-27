#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* 
    x86-64 gcc 5.1-10.1 -O2
    x86-64 clang 3.0.0 -O1
    arm gcc 5.4-9.2.1 -O2

*/

int main(int argc, char** argv) {
    char* a = (char*)malloc(1000);
    char* b = NULL;
    unsigned int len = 0;
    //scanf("%s",a);
    //scanf("%u",&len);
    len = atoi(argv[2]); //input 0
    for(int i = 0; i < len; i++){
		a[i] = argv[1][i];  //input e.g. aa
    }
    if (len)
        b = (char*)malloc(1000);
    memcpy(b,a,len);
    printf("ok");
    if (b) {
        *b = 'a';
        printf("%s\n",b);
    }
    return 0;
}
