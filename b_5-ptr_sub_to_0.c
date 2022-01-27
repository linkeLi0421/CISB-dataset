#include<stdio.h>
#include <stdlib.h>

__attribute__((noinline))
void changePtr(char **p) {
    *p = (char*)1;
}

int main(){
    char *src;
    changePtr(&src);
    src--;
    if (src) {
        printf("check 1");
    }
    else {
        printf("check 0");// src = 0
    }
    return 0;
}