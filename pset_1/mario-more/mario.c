// Draw a mario pyramide
#include <cs50.h>
#include <stdio.h>

void drawBlocks(int block);
void drawSpace(int space);
int promptHeight(void);
void assembleFunc(int input);

int main(void) 
{   
    // Prompt for user input
    int input = promptHeight();

    // Draw blocks and spaces
    assembleFunc(input);
}


// Prompt for user input
int promptHeight(void)
{
    int input;

    do
    {

        input = get_int("Height: ");
    }
    while (input < 0 || input > 8);
    return input;
}

// Assemble two parts of pyramide
void assembleFunc(int input)
{
    for (int i = input; i != 0; i--)
    {
        //First part of a pyramide
        drawSpace(i - 1);
        drawBlocks((input + 1) - i);
        //Second part of a pyramide
        drawSpace(2);
        drawBlocks((input + 1) - i);
        printf("\n");
    }
}

// Draw blocks
void drawBlocks(int block)
{
    for (int i = block; i != 0; i--)
    {
            printf("#");
    }
}

// Draw spaces
void drawSpace(int space)
{
    for (int i = space; i != 0; i--)
    {
        printf(" ");
    }
}
