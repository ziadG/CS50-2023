#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);

int main (void)
{
    int x = 0;
    int y = 0;
    int z = 0;

    int result = valid_triangle(x,y,z);
}


bool valid_triangle(int a, int b, int c)
{


    a = 0;
    b = 0;
    c = 0;

    do
    {
        a = get_int("enter the first positive integer: ");
        b = get_int("enter the second positive integer: ");
        c = get_int("enter the third positive integer: ");
    }
    while (a <= 0 || b <= 0 || c <= 0);

    if (a + b <= c || b + c <= a || a + c <= b)
    {
        printf("FALSE\n");
        return false;
    }
    else
    {
        printf("TRUE\n");
        return true;
    }

}


