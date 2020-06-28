#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/**
    * Note: The returned array must be malloced, assume caller calls free().
**/
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize) {
    int i = 0;
    int j = 0;
    int max = 0;
    bool *result = NULL;

    result = (bool *)malloc(candiesSize * sizeof(bool));
    if (result == NULL) {
        return NULL;
    }
    *returnSize = candiesSize;

    max = candies[0];

    for (i = 0; i < candiesSize; i++) {
        if (max < candies[i]) {
            max = candies[i];
        }
        result[i] = false;
    }

    for (i = extraCandies; i > 0; i--) {
        for (j = 0; j < candiesSize; j++) {
            if ((candies[j] + i) >= max)  {
                result[j]  = true;
            }
        }
    }

    return result;
}

int main(void) {
    int returnSize = 0;
    int kindies1[] = {2, 3, 5, 1, 3};
    int kindies2[] = {4, 2, 1, 1, 2};
    int kindies3[] = {12, 1, 12};

    kidsWithCandies(kindies1, sizeof(kindies1) / sizeof(kindies1[0]), 3, &returnSize);
    kidsWithCandies(kindies2, sizeof(kindies2) / sizeof(kindies2[0]), 1, &returnSize);
    kidsWithCandies(kindies3, sizeof(kindies3) / sizeof(kindies3[0]), 10, &returnSize);

    return 0;
}
