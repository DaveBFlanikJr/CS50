#include <cs50.h>
#include <stdio.h>

float get_lamas_start(void);
float get_lamas_end(float lamas);
float years_to_threshold(float lamas_start, float lamas_end);

int main(void)
{
    float years; // Declare the variable 'years'

    // TODO: Prompt for start size
    float lamas_start = get_lamas_start();

    // TODO: Prompt for end size
    float lamas_end = get_lamas_end(lamas_start);

    // TODO: Calculate number of years until we reach threshold
    years = years_to_threshold(lamas_start, lamas_end);

    // TODO: Print number of years
    printf("Years: %.2f.\n", years);
}

float get_lamas_start(void)
{
    int lamas;
    do
    {
        lamas = get_int("How many lamas are there?\n");
        // if the user enters a number less than 9 (the minimum allowed population size), the user should be re-prompted to enter a
        // starting population
        if (lamas < 9)
        {
            printf("Please enter a population size greater than 9\n");
        }
    }
    while (lamas <= 8);
    // printf("Start size: %d\n", lamas);
    return lamas;
}

float get_lamas_end(float lamas)
{
    int lamas_end;
    // should be no less than the starting population.. If it is the user must re-prompt (greater or equal)
    do
    {
        lamas_end = get_int("How many lamas do you want to have eventually?\n");
        if (lamas_end < lamas)
        {
            printf("Please enter a population size greater than or equal to the starting population of %f\n", lamas);
        }
    }
    while (lamas_end < lamas);
    // printf("End size: %d\n", lamas_end);
    return lamas_end;
}

float years_to_threshold(float lamas_start, float lamas_end)
{
    if (lamas_start >= lamas_end)
    {
        return 0;
    }

    int years = 0;

    float population = lamas_start;

    while (population < lamas_end)
    {
        // Calculate the number of lamas born this year.
        int lamas_born = population / 3.0;

        // Calculate the number of lamas that die this year.
        int lamas_died = population / 4.0;

        // Calculate the new population.
        population = population + lamas_born - lamas_died;

        // Increment the number of years.
        years++;
    }

    return years;
}
