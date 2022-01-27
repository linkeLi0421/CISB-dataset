#include<stdio.h>
#include<pthread.h>
int x = 1;

__attribute__((noinline))int foo(int b){
    // barrier();       // with barrier, wont be removed
    return b + x;
}

void* set_x() {
    while(1)
        x += 1;
}

int main(){
    pthread_t p1;
    pthread_create(&p1, NULL, set_x, NULL);
    int i;
    for(i = 0; i < 10000000; i++)
    ;
    int k, m;
    k = foo(100);
    
    m = k + 1;
    k = foo(100);           //  removed in x86-64 all version of gcc and clang with -O in compiler explorer
    printf("%d %d", k, m);
}