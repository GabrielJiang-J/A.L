#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uniquePaths(int m, int n) {
	int i, j;
	int total;
	int *nums = (int *)malloc(m * n * sizeof(int));
	memset(nums, 0, m * n * sizeof(int));

	nums[0] = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)	 {
			if (i > 0 && j > 0) {
				nums[i * n + j] = nums[(i - 1) * n + j] + nums[i * n + j - 1];
			} else if (i > 0) {
				nums[i * n + j] = nums[(i - 1) * n + j];
			} else if (j > 0) {
				nums[i * n + j] = nums[i * n + j - 1];
			}
		}
	}
	total = nums[m * n - 1];
	free(nums);
	return total;
}

void main(void) {
	printf("3 * 7 = %d\n", uniquePaths(3, 7));
	printf("3 * 2 = %d\n", uniquePaths(3, 2));
}
