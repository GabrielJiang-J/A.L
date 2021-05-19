#include <stdio.h>

/*
    分类：内部比较排序;
    时间复杂度：O(nlogn), O(n^2), O(nlogn);
    空间复杂度：O(nlogn);
    稳定性：不稳定;
 */

int quick_helper(int *nums, int left, int right)
{
    int p = nums[left];

    while (left < right) {
        while (left < right && nums[right] > p) 
            right--;
        nums[left] = nums[right];

        while (left < right && nums[left] < p)
            left++;
        nums[right] = nums[left];
    }

    nums[left] = p;

    return left;
}

void quick_sort(int *nums, int left, int right)
{
    int p = 0;

    if (left < right) {
        p = quick_helper(nums, left, right);
        quick_sort(nums, left, p - 1);
        quick_sort(nums, p + 1, right);
    }
}

int main(int argc, char *argv[])
{
#define SIZE 15
    int nums[SIZE] = {3, 4, 8, 10, 9, 1, 7, 2, 6, 5, 300, 100, 500, 1000, 600};
    
    quick_sort(nums, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", nums[i]); 
    }
    printf("\n");

    return 0;
}
