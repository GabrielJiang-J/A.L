#include <stdio.h>

/*
    分类：内部比较排序;
    时间复杂度：O(n^2), O(n^2), O(n^2);
    空间复杂度：O(1);
    稳定性：不稳定;
 */

void select_sort(int *nums, int len)
{
    int i, j, temp, min;

    for (i = 0; i < len - 1; i++) {
        min = i; 

        for (j = i + 1; j < len; j++)
            if (nums[min] > nums[j])
                min = j;

        if (min != i) {
            temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    int nums[10] = {3, 4, 8, 10, 9, 1, 7, 2, 6, 5};
    
    select_sort(nums, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]); 
    }
    printf("\n");

    return 0;
}
