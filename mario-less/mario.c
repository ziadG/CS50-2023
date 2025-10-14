//add a new comment

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;
    do
    {
        n = get_int("Enter a number between 1 and 8: ");

    }
    while (n < 1 || n > 8);

// main counter from 1 to n
    for (int i = 0; i < n; i++)
    {

// assign a new var. z to the main number n, compare to the counter, execute if true (from n towards i) then dexrease z to prevent an infinite loop
        for (int z = n - 1; z > i; z--)
        {
            printf(" ");
        }
// printing the # by making a new counter j if it's less than i it prints so we start printing from 1 all the way up to the value of n, this loop has to be within the main loop.
        for (int j = 0; j <= i; j++)
        {

            printf("#");
        }

        printf("\n");

    }

}