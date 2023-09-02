// Validate credit card number
#include <stdio.h>

long get_num(void);
long indent_card(long cardnum);

int main(void)
{
    // Ask user's card number
    long cardnum = get_num();

    // Identify the card
    long ind = indent_card(cardnum);

    // Print the result
    if (ind == 1)
    {
        printf("AMEX\n");
    }
    else if (ind == 2)
    {
        printf("MASTER\n");
    }
    else if (ind == 3)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}

long get_num(void)
{
    // Prompt user to enter a card number
    long i;
    do
    {
        printf("Number: ");
        scanf("%ld", &i);
    }
    while (i < 0);
    return i;
}

long indent_card(long cardnum)
{
    // Use Luhn's algorithm to identify the card
    long num = cardnum;
    int count = 0, sum = 0, even = 0, digit_1 = 0, digit_2 = 0;
    while (num > 0)
    {
        long digit = num % 10;
        // Counts the digits
        count++;
        // Check if it's even
        even = count % 2;

        if (even == 0)
        {
            // Sum the other digit and multiply by two
            // then sum the result
            digit_2 = digit;
            digit = digit * 2;
            if (digit > 9)
            {
                while (digit > 0)
                {
                    int cont = digit % 10;
                    sum += cont;
                    digit /= 10;
                }
            }
            else
            {
                sum += digit;
            }
        }
        else
        {
            digit_1 = digit;
            sum += digit;
        }
        num /= 10;
    }

    if (count == 13 || count == 15 || count == 16)
    {
        // Check if count is even
        count %= 2;

        // Swap the variables
        if (count == 0)
        {
            digit_1 = digit_1 + digit_2;
            digit_2 = digit_1 - digit_2;
            digit_1 = digit_1 - digit_2;
        }

        // Check if the card is AMEX
        if (digit_1 == 3)
        {
            if (digit_2 == 4 || digit_2 == 7)
            {
                num = 1;
            }
        }

        // Check if the card is MASTER
        else if (digit_1 == 5)
        {
            if (digit_2 >= 1 && digit_2 <= 5)
            {
                num = 2;
            }
        }
        // Check if the card is VISA
        else if (digit_1 == 4)
        {
            num = 3;
        }
        else
        {
            num = 0;
        }
        sum %= 10;
        if (sum != 0)
        {
            num = 0;
        }
    }
    return num;
}
