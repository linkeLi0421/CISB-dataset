/*successful
    x86-64 gcc 4.1.2-10.1 -O2
    x86-64 clang 3.0.0 -O1
    x86-64 clang 4.0.0-11.0.0 -O2
    arm gcc 4.5.4-9.2.1 -O2
    arm clang 9.0.0-11.0.0 -O2
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

struct a {
    uint32_t t1;
    uint32_t t2;
};

int main() {
    struct a* tmp = (struct a*)malloc(sizeof(struct a));
	uint32_t t = tmp->t1;
	if (!tmp)
        return 0;
    printf("%u\n",t);
    return 0;
}