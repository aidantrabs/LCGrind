#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x) {    
    int num = x;
    long rev_num = 0;
    
    while (num > 0) {
        long palindrome = (num % 10);
        rev_num = (10 * rev_num + palindrome);
        num /= 10;
    } 
    
    return rev_num == x;
}

int main() {
     int x = 121;
     bool result = isPalindrome(x);
     printf("%d is %s a palindrome number \r ", x, result ? "" : "not");
     return 0;
}