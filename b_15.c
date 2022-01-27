#include <stdio.h>
void* vgPlain_memset( void *destV, int c, int sz )
{
     char* d = (char*)destV;
     while (sz >= 1) {
        d[0] = c;
        d++;
        sz--;
     }
     return destV;
}

 void* memset(void *s, int c, int n) {
	printf("hello\n");
 	return vgPlain_memset(s,c,n);
 }

int main(int argc, char** argv){
//input abcde
	char* str = argv[1];
	memset(str, 97, 5);
	puts(str);
}