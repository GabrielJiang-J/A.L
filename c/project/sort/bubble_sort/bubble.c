#include <stdio.h>

/*
    分类：内部比较排序;
    时间复杂度：O(n), O(n^2), O(n^2);
    空间复杂度：O(1);
    稳定性：稳定;
 */

void bubble_sort(int *nums, int len)
{
    int i, j, tmp;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        } 
    }
}

int main(int argc, char *argv[])
{
    int nums[10] = {3, 4, 8, 10, 9, 1, 7, 2, 6, 5};
    
    bubble_sort(nums, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]); 
    }
    printf("\n");

    return 0;
}
