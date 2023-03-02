/*
	x86-64 gcc4.1-7.4 -O1; gcc 8-12 -O0
	x86-64 clang3.0.0-14.0.0 -O1
	Compile and run the program, if output is "ok", it means assert(a+100 > a) is removed, so there is a bug.
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