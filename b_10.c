#include    <stdio.h>

int main (void)
{
    int x=0, y=0;
    long z=0;
    
    for (; y<10000000; y++) {
        
        if (y%7 == 0)
            continue;
               
        x = 0;
                
        while (x<10000000000) {  // KEY LINE - see below
            
            x++;
            z+=1;
        }
    }
    
    printf ("%li\n", z);
    
    return  0;
}