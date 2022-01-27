// constructed case:
#include <stdio.h>
#include <stdlib.h>

int x,y;


void m(){
      x++;
}

// void (* testptr)() = m;


struct  c{
      int c1;
      void (* testptr)();
};



struct c k = {0, m};

// __attribute__((noinline))int foo1(int a){
//     return a ;

// }

__attribute__((inline))int flag_is_changeable_p(int flag){
    // return a ;
    unsigned int f1, f2;
	asm  ("pushfl\n\t"                  // this asm code load flag reg
		      "pushfl\n\t"
		      "popl %0\n\t"
		      "movl %0,%1\n\t"
		      "xorl %2,%0\n\t"
		      "pushl %0\n\t"
		      "popfl\n\t"
		      "pushfl\n\t"
		      "popl %0\n\t"
		      "popfl\n\t"
		      : "=&r" (f1), "=&r" (f2)
		      : "ir" (flag)
              );
              

	return ((f1^f2) & flag) != 0;

}

__attribute__((noinline)) int have_cpuid_p(void)
{
	return flag_is_changeable_p(1);
}

__attribute__((noinline))void foo2(){
    x++;
    // k.testptr();
}

int main(){
    int lm = 1, ln = 2;
    if (x > y) puts("0");
    if (have_cpuid_p())
        foo2();
    if (have_cpuid_p())
        puts("aaa");

    printf("%d", x);
    return 0;
}