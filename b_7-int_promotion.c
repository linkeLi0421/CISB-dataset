/*successful
    x86-64 gcc 4.4-trunk -O1
    x86-64 clang 3.0.0-trunk -O1
*/
#include <stdio.h>
#include <stdlib.h>

void test(unsigned char a){
    if(a + 1)                   // removed
        printf("ok\n");
    unsigned char b = a + 1;
	printf("%d\n", a);
}

int main(int argc, char* argv[]){
    //int i = 255;
    char i = atoi(argv[1]);//input 255
    printf("%d\n", i);
    test(i);
}