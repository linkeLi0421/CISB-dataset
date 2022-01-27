/*
	x86-64 gcc4.5.3-7.1 O2
	x86-64 gcc8- O1
	arm gcc4-7 O2 
	arm gcc8- O1
*/

//比较bad_code段里有没有test指令
#include <stdio.h>

void bad_code(void *a)
{
   int *b = a;
   int c = *b;
   static int d;

   if (b) {
      d = c;
   }
   printf("%d\n",d);
}

int main(int argc, char** argv){
	int a = atoi(argv[1]);
	bad_code(&a);
}