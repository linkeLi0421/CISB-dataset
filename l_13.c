#include<stdio.h>

struct ccc{
    int a;
    int b
} c;

__attribute__((noinline))
int test(struct ccc *t) {
    //printf("%d", &t->b);
    if (!&t->b) {
        printf("ok");
    }
    return 0;
}

int main() {
    test((struct ccc *)0xfffffffffffffffc);
    return 0;
}

