#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{

    string name = get_string("enter a string: ");
    int length = strlen(name);

    for (int i = 0; i < length; i++)
    {
        if name[i] > 97
        {
            printf("It's uppercase");
        }
        else
        {
            printf("it's lowercase");
        }

    }



}