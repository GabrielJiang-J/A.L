#include <stdio.h>

/*
 * Detect if two integers have opposite signs.
 * */
int detect_opposite_sign(int x, int y) {
    return ((x ^ y) < 0);
}

int main(void) {
    printf("%d\n", detect_opposite_sign(1, 2));
    printf("%d\n", detect_opposite_sign(1, -2));
}
