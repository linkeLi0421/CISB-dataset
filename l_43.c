#include<stdio.h>

unsigned int a[100];

int main() {
    for (int i = 0; i < 100; ++i) {
        a[i] = 0x11111111;
    }
    return 0;
}
