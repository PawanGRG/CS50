#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    int number;
    int array[BITS_IN_BYTE];
    int counter = 0;

    string input = get_string("Message: ");
    for (int i = 0; i < strlen(input); i++)
    {
        counter = 0;
        number = input[i];
        for (int j = 128; j > 0;)
        {
            if (j > number)
            {
                array[counter] = 0;
                counter++;
            }
            else
            {
                number = number - j;
                array[counter] = 1;
                counter++;
            }
            j = j / 2;
        }

        for (int a = 0; a < BITS_IN_BYTE; a++)
        {
            print_bulb(array[a]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}