#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_sum(long number);
bool check(long first, int check);

int main(void)
{
    long num;

    do
    {
        num = get_long("Number: ");
    }
    while (num < 1);

    check_sum(num);
}

int check_sum(long number)
{
    int digit;
    int sum = 0;
    int count = 0;
    const long num = number;
    while (number > 0)
    {
        digit = number % 10;
        number = number / 10;
        count ++;

        if (count % 2 == 0)
        {
            digit = digit * 2;

            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }

        sum = sum + digit;
    }

    if (sum % 10 == 0 && count == 15)
    {
        if (check(num, 37) || check(num, 34))
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else if (sum % 10 == 0 && count == 16)
    {
        if (check(num, 51) || check(num, 52) || check(num, 53) || check(num, 54) || check(num, 55) )
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (check(num, 4))
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else if (sum % 10 == 0 && count == 13)
    {
        if (check(num, 4))
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 1;
        }
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }
}

bool check(long first, int check)
{
    if (check >= 1 && check < 10)
    {
        while (first >= 10)
        {
            first = first / 10;
        }
    }
    else
        while (first >= 100)
        {
            first = first / 10;
        }

    return first == check;
}