#include <stddef.h>
#include <stdlib.h>

int xorOperation1(int n, int start) {
    int i = 0;
    int *nums = NULL;
    int x = 0;

    nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        nums[i] = start + 2 * i;
    }

    x = nums[0];
    for (i = 1; i < n; i++) {
        x ^= nums[i];
    }

    free(nums);
    nums = NULL;

    return x;
}

int xorOperation2(int n, int start) {
    int i = 0;
    int x = start;

    for (i = 1; i < n; i++) {
        start += 2;
        x ^= start;
    } 

    return x;
}

int main(void) {
    xorOperation1(5, 0);
    xorOperation2(5, 0);

    return 0;
}
