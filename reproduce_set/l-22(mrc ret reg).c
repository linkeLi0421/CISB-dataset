// https://github.com/torvalds/linux/commit/a99632014631409483a481a6a0d77d09ded47239
#define uint32_t unsigned int 
#define DCC_STATUS_TX		(1 << 29)
#define cpu_relax()			barrier()

static inline uint32_t __dcc_getstatus(void)
{
	uint32_t __ret;
	asm("mrc p14, 0, %0, c0, c1, 0	@ read comms ctrl reg" // 
		: "=r" (__ret) : : "cc");

	return __ret;
}

static inline void __dcc_putchar(char c)
{
	asm("mcr p14, 0, %0, c0, c5, 0	@ write a char"
		: /* no output register */
		: "r" (c));
}



 int hvc_dcc_put_chars(uint32_t vt, const char *buf, int count)
{
	int i;

	for (i = 0; i < count; i++) {
		while (__dcc_getstatus() & DCC_STATUS_TX)   // if line 9 not marked volatile, compile will restore 
                                                    // __ret value in r7(or other reg), reuse it without call the func
                                                    // ARM all version with -O with both gcc clang
			cpu_relax();

		__dcc_putchar(buf[i]);
	}

	return count;
}


/*
asm code:

hvc_dcc_put_chars:
        push    {r3, r4, r5, r6, r7, lr}
        subs    r7, r2, #0
        ble     .L2
        subs    r5, r1, #1
        mrc p14, 0, r4, c0, c1, 0       @ read comms ctrl reg 	
        adds    r6, r5, r7				
        and     r4, r4, #536870912
.L10:
        cbz     r4, .L12
.L4:
        bl      barrier
        cmp     r4, #0						// while loop donot exe __dcc_getstatus, just refer to reg r4
        bne     .L4
.L12:
        ldrb    r3, [r5, #1]!   @ zero_extendqisi2
        mcr p14, 0, r3, c0, c5, 0       @ write a char
        cmp     r5, r6
        bne     .L10
.L2:
        mov     r0, r7
        pop     {r3, r4, r5, r6, r7, pc}
*/