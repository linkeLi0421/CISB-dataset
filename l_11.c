#include<stdio.h>

struct foo {
    char a;
    int b;
    short c;
    int d;
};

int main() {
    printf("%d", sizeof(struct foo));
    return 0;
}