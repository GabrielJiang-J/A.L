#include <stdbool.h>

bool isPalindrome(int x){
    int p = 0;

    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }   

    while (x > p) {
        p = (x % 10) + p * 10; 
        x = x / 10; 
    }

    if (x == p || x == p / 10) {
        return true;
    }

    return false;
}

int main(void) {
    isPalindrome(121);
    isPalindrome(100);
    isPalindrome(133);
    isPalindrome(0);
    isPalindrome(-121);
    isPalindrome(123454321);
    isPalindrome(1234321);

    return 0;
}
