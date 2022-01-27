/*
	successful
	x86-64 gcc5-gcc11.2 O1
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
static char*  const kern_buff_p;

void hello_start()
{

 if(!kern_buff_p)
        printf("buffer is NULL for first time \n");

  *((char**)(unsigned long int)((&kern_buff_p)))=(char*)malloc(10);

 if(!kern_buff_p)
        printf("buffer is NULL for second time \n");
}

int main(){
    hello_start();
}