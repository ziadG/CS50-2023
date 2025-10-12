#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n = get_int("enter a number: ");
    int array[n];


    for (int i = 0; i <= n; i++)
    {
        int m = i * 2;

        array[i] = m;

        printf("array: %i\n ",array[i]);
    }


}