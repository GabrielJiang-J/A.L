#include <stdio.h>
#include <stdint.h>


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

/*
 * 计算二进制位中1的个数。
 * */
int hamming_weight_1(uint32_t n) {
    int i = 0;
    int count = 0;
    int mask = 1;

    for (i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            count++;
        }

        mask <<= 1;
    }

    return count;
}

int hamming_weight_2(uint32_t n) {
    int count = 0;

    while (n != 0) {
        n &= (n - 1);
        count++;
    }

    return count;
}


int main(void) {
    int count = 0;

    int k = 255;
    print_bits(k);
    count = hamming_weight_1(k);
    printf("%d\n", count);

    k = 255;
    print_bits(k);
    count = hamming_weight_2(k);
    printf("%d\n", count);

    return 0;
}
