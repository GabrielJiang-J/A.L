#include <stdio.h>
#include <limits.h>

int min_no_branch_1(int x, int y) {
    int r = 0;

    r = y ^ ((x ^ y) & (-(x < y)));

    return r;
}

int min_no_branch_2(int x, int y) {
    int r = 0;

    r = y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));

    return r;
}

int max_no_branch_1(int x, int y) {
    int r = 0;

    r = x ^ ((x ^ y) & (-(x < y)));

    return r;
}

int max_no_branch_2(int x, int y) {
    int r = 0;

    r = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));

    return r;
}

int main(void) {

    printf("%d\n", min_no_branch_1(1, 2));
    printf("%d\n", max_no_branch_1(1, 2));
    printf("%d\n", min_no_branch_2(3, 9));
    printf("%d\n", max_no_branch_2(3, 9));

    return 0;
}
