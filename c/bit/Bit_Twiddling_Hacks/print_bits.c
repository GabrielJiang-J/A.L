#include <stdio.h>

/*
 * print integer numbers every bit.
 * */
void print_bits(int k) {
    int i = 0;

    for (i = 8 * sizeof(int) - 1; i >= 0; i--) {
        printf("%d", (k >> i) & 1);       
        if ((i % 4) == 0 && i != 0) {
            printf(" ");
        }
    }

    printf("\n");
}

int main(void) {
    print_bits(0xff);
}
