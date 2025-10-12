#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // prompting the user for the card number, it has to be positive
    long number;
    do
    {
        number = get_long("Number: ");

    }
    while (number < 0);
    // counting the length of the number, storing the card number in another var called r to prevent the number itself from changing
    long r = number;
    int count = 0;
    do
    {
        r /= 10;
        count++;
    }
    while (r != 0);
    // all and any comment including print of was because I needed to see what was happening

//printf("count: %i" " %li\n ",count,number);

    // pow is for the power of present in <math.h> header.
    // the following code is to get the first two digits of the card number
    long amchk = number / pow(10, count - 2);
    long mchk = number / pow(10, count - 2);
    long vchk = number / pow(10, count - 1);
//printf("%li\n %li\n %li\n",amchk, mchk, vchk);

// looping through the card number by dividing by 10 to the power of 1,2,3....i etc. and doing the math (multiply by 2 then sum).
    int sum = 0;
    int x;
    for (int i = 1; i < count; i = i + 2)
    {
        long m = number / pow(10, i);
        x = m % 10;
        x = x * 2;
        if (x >= 10)
        {
            x = x / 10 + (x % 10);
//printf("%i\n",x);
        }
        else
        {
//printf("%i\n",x);
        }
        sum += x;
    }
//printf("sum: %i\n",sum);

    int y;
    int f = 0;
    for (int z = 0; z < count; z = z + 2)
    {

        long n = number / pow(10, z);
        y = n % 10;
        //printf("%i\n",y);
        f += y;

    }
//printf("second sum: %i\n", f);

    int total = f + sum;
//printf("total: %i\n", total);
    int l;
    l = total % 10;
//printf("module: %i\n",l);

// matching each card with it's type
    if (l == 0)
    {
        if (count == 15)
        {
            if (amchk == 37)
            {
                printf("AMEX\n");
            }
            else if (amchk == 34)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 16)
        {
            if (mchk == 51)
            {
                printf("MASTERCARD\n");
            }
            else if (mchk == 52)
            {
                printf("MASTERCARD\n");
            }
            else if (mchk == 53)
            {
                printf("MASTERCARD\n");
            }
            else if (mchk == 54)
            {
                printf("MASTERCARD\n");
            }
            else if (mchk == 55)
            {
                printf("MASTERCARD\n");
            }
            else if (vchk == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 13)
        {
            if (vchk == 4)
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}