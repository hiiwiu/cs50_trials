#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

	int a;
    do
    {
	    a = get_int("Start size: ");
    }
    while (a < 9);

    // TODO: Prompt for end size
   	
    	int b;
    do
    {
	    b = get_int("End size: ");
    }
    while (b < a);

    // TODO: Calculate number of years until we reach threshold
    	
    	int i = 0; //itteration -- years
    	int n;

	if (a == b)
	{
		i = 0;
	}
	else
	{
    do
    {
	    a = a + (a / 3) - (a / 4);
	    i++;
    }
    while (a < b);
	}

    // TODO: Print number of years
    
	    printf("Years: %i\n", i);
}
