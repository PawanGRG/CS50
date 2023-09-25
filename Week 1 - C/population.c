#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for start size
    int start_size = get_int("Start size: ");
    while (start_size < 9)
    {
        start_size = get_int("Start size: ");
    }

    //Prompt for end size
    int end_size = get_int("End size: ");
    while (end_size < start_size)
    {
        end_size = get_int("End size: ");
    }

    // How many years will it take to go from starting population size to the end population size
    int years = 0;
    int gain = 0;
    int loss = 0;

    while (start_size < end_size)
    {
        gain = (start_size / 3);
        loss = (start_size / 4);
        start_size = start_size + gain - loss;
        years += 1;
    }

    // Print number of years
    printf("Years: %i \n", years);
}