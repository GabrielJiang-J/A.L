#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fib(int n, int *memo) {
    if (memo[n] != -1) {
        return memo[n];
    }

    if (n <= 2) {
        memo[n] = 1;
    } else {
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    }

    return memo[n];
}
int fibonacci_memo(int n) {
    int *memo = NULL;
    int i = 0;

    memo = (int *)malloc(sizeof(int) * (n + 1));
    if (memo == NULL) {
        return -1;
    }
    for (i = 0; i < n + 1; i++) {
        memo[i] = -1;
    }

    return fib(n, memo);
}

int fibonacci_loop(int n) {
    int i = 0;
    int *memo = NULL;

    memo = (int *)malloc(sizeof(int) * (n + 1));
    if (memo == NULL) {
        return -1;
    }
    memset(memo, 0, sizeof(int) * (n + 1));
    
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    for (i = 2; i < n + 1; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int fibonacci_no_array(int n) {
    int i = 0;

    int memo_i = 1;
    int memo_i_1 = 1;
    int memo_i_2 = 0;

    for (i = 2; i < n + 1; i++) {
        memo_i = memo_i_1 + memo_i_2;
        memo_i_2 = memo_i_1;
        memo_i_1 = memo_i;
    }

    return memo_i;
}

int main(void) {
    printf("%d\n", fibonacci(6));
    printf("%d\n", fibonacci_memo(6));
    printf("%d\n", fibonacci_loop(6));
    printf("%d\n", fibonacci_no_array(6));

    return 0;
}
