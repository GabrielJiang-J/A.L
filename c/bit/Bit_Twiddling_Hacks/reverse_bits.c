#include <stdio.h>
#include <stdint.h>
#include <limits.h>

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

int reverse_bits_1(uint32_t k) {
    uint32_t ret = 0;
    uint32_t power = 31;

    while (k != 0) {
        ret |= (k & 1) << power;
        k = k >> 1;
        power--;
    }

    return ret;
}

int reverse_bits_2(unsigned int k) {
    unsigned int r = k;
    int s = sizeof(k) * CHAR_BIT - 1;

    for (k >>= 1; k; k >>= 1) {
        r <<= 1;
        r |= k & 1;
        s--;
    }

    r <<= s;

    return r;
}

/*
 * 采用分治的策略，我们通过掩码将 32 位整数划分成具有较少位的块，
 * 然后通过将每个块反转，最后将每个块的结果合并得到最终结果。
 *
 * */
int reverse_bits_3(uint32_t k) {
    int res = k;

    printf("-------------------------------\n");
    print_bits(res);
    res = ((res & 0xffff0000) >> 16) | ((res & 0x0000ffff) << 16);
    print_bits(res);
    res = ((res & 0xff00ff00) >> 8) | ((res & 0x00ff00ff) << 8);
    print_bits(res);
    res = ((res & 0xf0f0f0f0) >> 4) | ((res & 0x0f0f0f0f) << 4);
    print_bits(res);
    res = ((res & 0xcccccccc) >> 2) | ((res & 0x33333333) << 2);
    print_bits(res);
    res = ((res & 0xaaaaaaaa) >> 1) | ((res & 0x55555555) << 1);
    print_bits(res);
    printf("-------------------------------\n");

    return res;
}

/*
 *
 * Reverse the bits in a byte with 3 operations (64-bit multiply and modulus division)
 * */
unsigned char reverse_byte_4(unsigned char b) {
    return (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
}
uint32_t reverse_bits_4(uint32_t k) {
    int power = 24;
    uint32_t res = 0;

    while (k != 0) {
        res |= reverse_byte_4(k & 0xff) << power;
        k >>= 8;
        power -= 8;
    }

    return res;
}

/*
 *
 * Reverse the bits in a byte with 4 operations (64-bit multiply, no division)
 * */
unsigned char reverse_byte_5(unsigned char b) {
    return ((b * 0x80200802ULL) & 0x0884422110ULL) * 0x0101010101ULL >> 32;
}
uint32_t reverse_bits_5(uint32_t k) {
    int power = 24;
    uint32_t res = 0;

    while (k != 0) {
        res |= reverse_byte_5(k & 0xff) << power;
        k >>= 8;
        power -= 8;
    }

    return res;
}

/*
 *
 * Reverse the bits in a byte with 7 operations (no 64-bit)
 * */
unsigned char reverse_byte_6(unsigned char b) {
    return ((b * 0x0802LU & 0x22110LU) | (b * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16;
}
uint32_t reverse_bits_6(uint32_t k) {
    int power = 24;
    uint32_t res = 0;

    while (k != 0) {
        res |= reverse_byte_6(k & 0xff) << power;
        k >>= 8;
        power -= 8;
    }

    return res;
}

int main(void) {
    uint32_t k = 0;
    uint32_t nk = 0; 

    k = 0x125;
    print_bits(k);
    nk = reverse_bits_1(k);
    print_bits(nk);
    printf("\n");

    k = 0x125;
    print_bits(k);
    nk = reverse_bits_2(k);
    print_bits(nk);
    printf("\n");

    k = 0x125;
    print_bits(k);
    nk = reverse_bits_3(k);
    print_bits(nk);
    printf("\n");

    k = 0x125;
    print_bits(k);
    nk = reverse_bits_4(k);
    print_bits(nk);
    printf("\n");

    k = 0x125;
    print_bits(k);
    nk = reverse_bits_5(k);
    print_bits(nk);
    printf("\n");

    k = 0x125;
    print_bits(k);
    nk = reverse_bits_6(k);
    print_bits(nk);
    printf("\n");



    return 0; 
}
