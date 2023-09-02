#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    } 
    while (min >= max);
    
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // Check if the number is prime

    int check;

    if (number == 1)
    {
        return false;
    }

    for (int n = number - 1; n != 1; n--)
    {
       check = number % n;
       
       if (check == 0)
       {
           return false;
       }
    }
    return true;
}
