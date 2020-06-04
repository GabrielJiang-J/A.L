#include <stdio.h>
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

int abs_no_branch_1(int n) {
    int r = 0;
    int mask = n >> (sizeof(int) * CHAR_BIT - 1);

    printf("----\n");
    print_bits(mask);
    print_bits(n + mask);
    print_bits(((n + mask) ^ mask));
    printf("----\n");

    r = (n + mask) ^ mask;

    return r;
}

int abs_no_branch_2(int n) {
    int r = 0;
    int mask = n >> (sizeof(int) * CHAR_BIT - 1);

    r = (n ^ mask) - mask;

    return r;
}

int main(void) {
    printf("%d\n", abs_no_branch_1(-100));
    /*
    print_bits(-100);
    printf("%d\n", abs_no_branch_1(-100));

    printf("%d\n", abs_no_branch_2(200));
    printf("%d\n", abs_no_branch_2(-200));
    */

    return 0;
}
