// https://github.com/torvalds/linux/commit/02828845dda5ccf921ab2557c6ca17b6e7fc70e2
#define prefetch(ptr)				\
	({					\
		__asm__ __volatile__(		\
		"pld\t%0"			\
		:				\
		: "o" (*(char *)(ptr))		\
		: "cc");			\
	})

extern void bar(char *x);
void foo(char *x)
{
	prefetch(x);
	if (x)                  //  x86-64  gcc 4.1.2 -O2
		bar(x);
}

/*
asm code:
foo:
        pld     BYTE PTR [%rdi]
        jmp     bar
*/
