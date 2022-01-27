#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    char* a = (char*)malloc(100);
    scanf("%s",a);
    printf("%s",a);
    memset(a,0,100);
    return 0;
}