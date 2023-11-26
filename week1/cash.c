#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int cents;
    do
    {
        cents = get_int("How many cents are you owed?\n");
        if (cents < 0)
        {
            printf("Please enter a valid number\n");
        }
    }
    while (cents < 0);
    printf("Total Cents: %i\n", cents);
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int count = 0;
    int quarters = 25;
    while (cents >= quarters)
    {
        count++;
        cents = cents - quarters;
    }
    printf("Quarters: %i\n", count);
    return count;
}

int calculate_dimes(int cents)
{
    // TODO
    int count = 0;
    int dimes = 10;
    while (cents >= dimes)
    {
        count++;
        cents = cents - dimes;
    }
    printf("Dimes: %i\n", count);
    return count;
}

int calculate_nickels(int cents)
{
    // TODO
    int count = 0;
    int nickels = 5;
    while (cents >= nickels)
    {
        count++;
        cents = cents - nickels;
    }
    printf("Nickels: %i\n", count);
    return count;
}

int calculate_pennies(int cents)
{
    // TODO
    int count = 0;
    int pennies = 1;
    while (cents >= pennies)
    {
        count++;
        cents = cents - pennies;
    }
    printf("Pennies: %i\n", count);
    return count;
}
