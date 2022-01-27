/*
	x86-64 gcc4.1-11.2 -O2
*/
#include <stdio.h>
#include <assert.h>

int foo(int a) {
  assert(a+100 > a);
  printf("ok");
  return a;
}

int main() {
//   foo(100);
  foo(0x7fffffff);
}