#include <stdio.h>

int isPalindrome(int num);
int main()
{
    int number;

    printf("\nEnter A Number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
    {
        printf("\nThe Number is Palindrome.");
    }
    else
    {
        printf("\nThe Number is Not Palindrome.");
    }
    return 0;
}
int isPalindrome(int number)
{
    int remainder, reverse = 0, num = number;
    while (num != 0)
    {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    printf("\nReverse: %d", reverse);
    if (number == reverse)
    {
        return 1;
    }
    return 0;
}