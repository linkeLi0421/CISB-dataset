#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
For Linux the correct command is: gcc -pthread b_12.c
if there is something like         
.L7:
jmp .L7
in assembly code，there is a bug.
*/


int x = 23;
int y = 29;

void* set_x(void* arg)
{
    (void)arg;
    x = 29;

    return NULL;
}

int main(void)
{

        pthread_t p1;

        pthread_create(&p1, NULL, set_x, NULL);
        pthread_detach(p1);
        while (x < y)
                if (x == y)
                        break;

        return 0;
}
