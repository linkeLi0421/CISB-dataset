#include<stdio.h>

#define DMA_ADDR_REG		(*(unsigned volatile *) 0xffff1000)

extern void panic(void);

static void inner_func(void *data, unsigned size)
{
	if (!size)
		exit(1);
	else {
        DMA_ADDR_REG = (unsigned long) data;
    }
		
}

void outer_func(unsigned offset, unsigned size)
{
	unsigned char param[1];

	param[0] = offset;


	inner_func(param, size);
}

int main() {
    puts("1");
    outer_func(1,1);
    // printf("%c", DMA_ADDR_REG);
    return 0;
}
