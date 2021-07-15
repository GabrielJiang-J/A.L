/**
    青蛙跳阶问题 

    f(n-1)和f(n-2)称为f(n)的最优子结构
    f(n)=f(n-1)+f(n-2)称为状态转移方程
    f(1)=1, f(2)=2就是边界
    f(10)=f(9)+f(8), f(9)=f(8)+f(7), f(8)就是重叠子问题
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numWays(int n)
{
   if (n == 1)  {
       return 1;
   }

   if (n == 2) {
       return 2;
   }

   return numWays(n - 1) + numWays(n - 2);
}

int numWays_memo(int n, int *memo) {
    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = numWays_memo(n - 1, memo) + numWays_memo(n - 2, memo);
    return memo[n];
}
int numWaysMemo(int n)
{
    int *num = NULL;
    int count = 0;

    if (n == 1) {
        return 1; 
    }

    if (n == 2) {
        return 2; 
    }

    num = (int *)malloc((n + 1) * sizeof(int));
    if (num == NULL) {
        return 0; 
    }

    memset(num, 0, n);
    num[1] = 1;
    num[2] = 2;

    count = numWays_memo(n, num);
    free(num);

    return count;
}

/**
  n = 1, f(n) = 1
  n = 2, f(n) = 2
  n > 2, f(n) = f(n-1)+f(n-2)
*/
int numWaysDP(int n)
{
    int i;
    int count;
    int *nums = NULL;

    nums = (int *)malloc(n * sizeof(int));
    if (nums == NULL)
        return 0;

    memset(nums, 0, n * sizeof(int));

    nums[0] = 1;
    nums[1] = 2;

    for (i = 2; i < n; i++) {
        nums[i] = nums[i - 1] + nums[i - 2];
    }

    count = nums[n - 1];

    free(nums);

    return count;
}

int main(int argc, char **argv)
{
    printf("%d order %d\n", 3, numWays(3));
    printf("%d order %d\n", 4, numWays(4));
    printf("%d order %d\n", 10, numWays(10));

    printf("%d order %d\n", 3, numWaysMemo(3));
    printf("%d order %d\n", 4, numWaysMemo(4));
    printf("%d order %d\n", 10, numWaysMemo(10));

    printf("%d order %d\n", 3, numWaysDP(3));
    printf("%d order %d\n", 4, numWaysDP(4));
    printf("%d order %d\n", 10, numWaysDP(10));
}
