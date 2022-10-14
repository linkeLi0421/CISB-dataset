/*successful
    x86-64 gcc 4.1.2-12.0.1 -O2
    x86-64 3.0.0-3.4.1 -O1; 3.0.0-14.0.0 -O2
    Compile and get disassembly code of this program. If section "<main>:" doesn't contains instruction "test", "if (!tmp)" is deleted, so there is a bug.
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