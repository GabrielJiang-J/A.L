#include <stdio.h>
#include <stdbool.h>

int is_power_of_two_1(int n) {
    return (n > 0 && ((n & (n - 1)) == 0));
}

/*
 * exclude 0.
 * */
bool is_power_of_two_2(int n) {
    return (n > 0 && !(n & (n - 1)));
}

int main() {
    printf("%d\n", is_power_of_two_1(4));
    printf("%d\n", is_power_of_two_1(256));
    printf("%d\n", is_power_of_two_1(257));
    printf("%d\n", is_power_of_two_1(0));
    printf("%d\n", is_power_of_two_2(0));
    printf("%d\n", is_power_of_two_2(-3));
    printf("%d\n", is_power_of_two_2(-4));

    return 0;
}
