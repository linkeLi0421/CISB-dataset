#include <stdio.h>

int main()
{
    int i;
    int data;
    int array[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    data=999;
    for (i=0; i<10; i++, 
    data=array[i])
    {
        if (array[i] == 99)
            break;
        printf("data=%d\n", data);
    }
    printf("Left loop. i=%d\n\n", i);
	return 0;
}