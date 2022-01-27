/*successful
    x86-64 gcc 8-trunk -O2
*/
#include <stdio.h>
#include <string.h>

#define MY_SIZE 16

int main(void)
{
        size_t ret, size;
        char src[MY_SIZE];
        char dst[MY_SIZE];

        memset(src, 'A', sizeof(src));
        memset(dst, 'B', sizeof(dst));

        //printf("MY_SIZE: %d\n", MY_SIZE);
        fflush(NULL);

        size = MY_SIZE;
        ret = strlen(src);
        
        //if (size) {
		size_t len = (ret >= size) ? size - 1 : ret;

		memcpy(dst, src, len);
		dst[len] = '\0';
        //}
		if (strlen(dst))
			printf("ok");
        //printf("dst: %zu\n", strlen(dst));
        fflush(NULL);
        //printf("done...\n");
        fflush(NULL);
        return 0;
}