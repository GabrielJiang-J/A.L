#include <stdio.h>

void rotate(int *nums, int numsSize, int k) {
    int t = 0;
    int i = 0;
    int j = 0;
    int p = 0;

    for (i = 0; i < k; i++) {
        p = nums[numsSize - 1];

        for (j = 0; j < numsSize; j++) {
		t = nums[j];
		nums[j] = p;
		p = t;
		
        }
    }
}

void print_nums(int *nums, int numsSize) {
    int i = 0;

    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void) {
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int nums2[] = {-1, -100, 3, 99};

    print_nums(nums1, sizeof(nums1) / sizeof(int));
    rotate(nums1, sizeof(nums1) / sizeof(int), 3);
    print_nums(nums1, sizeof(nums1) / sizeof(int));

    print_nums(nums2, sizeof(nums2) / sizeof(int));
    rotate(nums2, sizeof(nums2) / sizeof(int), 2);
    print_nums(nums2, sizeof(nums2) / sizeof(int));

    return 0; 
}
