#include <stdio.h>

int removeDuplicates_1(int *nums, int numsSize) {
    int i = 0;
    int j = 0;
    int mask[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (i = 0; i < numsSize; i++) {
        mask[nums[i]]++;
    }

    for (i = 0; i < 10; i++) {
        if (mask[i] != 0) {
            nums[j] = i;
            j++;
        }
    }

    return j + 1;
}

int removeDuplicates_2(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int i = 0;
    int j = 0;

    for (i = 0, j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}

void print_nums(int *nums, int numsSize) {
    int i = 0;

    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void) {
    int num1[] = {1, 1, 2};
    int num2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int len = 0;

    len = sizeof(num1) / sizeof(int);
    printf("%d\n", len);
    print_nums(num1, len);
    removeDuplicates_2(num1, len);
    print_nums(num1, len);

    len = sizeof(num2) / sizeof(int);
    print_nums(num2, len);
    removeDuplicates_2(num2, len);
    print_nums(num2, len);

    return 0;
}
