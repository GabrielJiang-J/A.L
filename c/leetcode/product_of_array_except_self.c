#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(int *nums, int len) {
    int i = 0;

    if (nums == NULL) {
        return;
    }

    for (i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
}

int *productExceptSelf_1(int *nums, int numsSize, int *returnSize) {
    (void)nums;
    (void)numsSize;
    (void)returnSize;

    int i = 0;

    *returnSize = numsSize;
    int *L = NULL;
    int *R = NULL;
    int *output = NULL;

    L = (int *)malloc(numsSize * sizeof(int));
    if (L == NULL) {
        goto error;
    }

    R = (int *)malloc(numsSize * sizeof(int));
    if (R == NULL) {
        goto error;
    }

    output = (int *)malloc(numsSize * sizeof(int));
    if (output == NULL) {
        goto error;
    }

    L[0] = 1;
    for (i = 1; i < numsSize; i++) {
        L[i] = L[i - 1] * nums[i - 1];
    }


    R[numsSize - 1] = 1;
    for (i = numsSize  - 2; i >= 0; i--) {
        R[i] = nums[i + 1] * R[i + 1];
    }

    for (i = 0; i < numsSize; i++) {
        output[i] = L[i] * R[i];
    }

    return output;

error:
    if (L != NULL) {
        free(L);
    }

    if (R != NULL) {
        free(R);
    }

    if (output != NULL) {
        free(output);
    }

    return NULL;
}

int *productExceptSelf_2(int *nums, int numsSize, int *returnSize) {
    (void)nums;
    (void)numsSize;
    (void)returnSize;

    int i = 0;
    int j = 0;
    int left = 1;
    int right = 1;

    *returnSize = numsSize;
    int *output = NULL;

    output = (int *)malloc(numsSize * sizeof(int));
    if (output == NULL) {
        return NULL;
    }

    for (i = 0; i < numsSize; i++) {
        output[i] = 1;
    }

    for (i = 0, j = numsSize - 1; i < numsSize; i++, j--) {
        output[i] *= left;
        left *= nums[i];
        output[j] *= right;
        right *= nums[j];
    }

    return output;
}



int main(void) {
    int nums[] = {1, 2, 3, 4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int *output = NULL;
    int return_len = 0;

    print_arr(nums, len);
    output = productExceptSelf_1(nums, sizeof(nums) / sizeof(nums[0]), &return_len);
    print_arr(output, return_len);
    free(output);

    print_arr(nums, len);
    output = productExceptSelf_2(nums, sizeof(nums) / sizeof(nums[0]), &return_len);
    print_arr(output, return_len);
    free(output);

    return 0;    
}
