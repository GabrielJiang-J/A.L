#include <stdio.h>

/*
 * Determining if an integer is a power of 2.
 * */
int test(int x) {
    return x && !(x & (x - 1));
}

int main(void) {
    printf("%d\n", test(0));
    printf("%d\n", test(3));
    printf("%d\n", test(4));
    printf("%d\n", test(9380));
}
