#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLIS(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;

    int i, j, max;
    int *dp = NULL;

    dp = (int *)malloc(numsSize * sizeof(int));
    if (dp == NULL)
        return 0;

    memset(dp, 0, sizeof(numsSize * sizeof(int)));

    dp[0] = 1;
    max = 1;

    for (i = 1; i < numsSize; i++) {
        dp[i] = 1;
        
        for (j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[i] <= dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] >= max)
            max = dp[i];
    }

    free(dp);

    return max;
}

int main(int argc, char **argv)
{
    int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int nums2[] = {0, 1, 0, 3, 2, 3};
    int nums3[] = {7, 7, 7, 7, 7, 7, 7};
    int nums4[] = {0};
    int max;

    max = lengthOfLIS(nums1, sizeof(nums1) / sizeof(int));
    printf("%d\n", max);
    max = lengthOfLIS(nums2, sizeof(nums2) / sizeof(int));
    printf("%d\n", max);
    max = lengthOfLIS(nums3, sizeof(nums3) / sizeof(int));
    printf("%d\n", max);
}
