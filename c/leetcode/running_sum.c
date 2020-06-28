#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int *running_sum(int *nums, int numsSize, int *returnSize){

    int i = 0;
    int *output = NULL;

    output = (int *)malloc(numsSize * sizeof(int));
    if (output == NULL) {
        returnSize = 0;
        return NULL;
    }
    memset(output, 0, numsSize * sizeof(int));
    *returnSize = numsSize;
    
    output[0] = nums[0];
    for (i = 1; i < numsSize; i++) {
        output[i] = nums[i] + output[i - 1];
    }

    return output;
}

int main(void) {
    int nums1[] = {1, 2, 3, 4};
    int nums2[] = {1, 1, 1, 1, 1};
    int returnSize = 0;

    running_sum(nums1, sizeof(nums1) / sizeof(nums1[0]), &returnSize);

    running_sum(nums2, sizeof(nums2) / sizeof(nums2[0]), &returnSize);

    return 0;
}
