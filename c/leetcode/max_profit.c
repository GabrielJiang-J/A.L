#include <stdio.h>

int maxProfit_1(int *prices, int pricesSize){
    int i = 0;
    int j = 0;
    int max = 0;
    int cur = 0;
    int sum = 0;

    for (i = 0; i < pricesSize; i++) {
        for (j = i + 1; j < pricesSize - i + 1; j++){
            cur = prices[j] - prices[i];

            if (cur >= 0 && cur > max) {
                max = cur;
            }
        }

        sum += max;
    }

    return sum;
}


/*
 * dp算法。
 * */
int maxProfit_2(int *prices, int pricesSize){
   int maxprofit = 0;
   for (int i = 1; i < pricesSize; i++) {
       if (prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[i - 1];
   }
    return maxprofit;
}

int main(void) {
    int num1[] = {7, 1, 5, 3, 6, 4}; // 7
    int num2[] = {1, 2, 3, 4, 5}; // 4 
    int num3[] = {7, 6, 4, 3, 1}; // 0

    printf("%d\n", maxProfit_2(num1, sizeof(num1) / sizeof(int)));
    printf("%d\n", maxProfit_2(num2, sizeof(num2) / sizeof(int)));
    printf("%d\n", maxProfit_2(num3, sizeof(num3) / sizeof(int)));

    return 0;
}
