#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);

int main(void)
{
    //TODO
    //askin the user for a message
    string text = get_string("Message: ");
    int length = strlen(text);

    // an array to store the decimal values of the text
    int total[8] = {};
    //Looping through the text to store each character's decimal value
    for (int i = 0; i < length; i++)
    {
        total [i] = text[i];
        printf("%i\n",total[i]);
    }
    char binary[8] = {};


    for (int i = 0; i < length; i++)
    {
        int counter = 0;
        int dec = total[i];
        for (int j = 0; dec != 0 ; j++)
        {
            if ((dec % 2) == 0)
            {
                binary[j] ='0';
                printf("%c",binary[j]);

            }
            else if ((dec % 2) > 0)
            {
                binary[j] = '1';
                printf("%c",binary[j]);
            }
            dec = dec / 2;
            counter++;
        }

        int len = strlen(binary);
        for (int z = 0; z <= 7; z++)
        {
            if (binary[7 - z] =='1')
            {
                printf("\U0001F7E1 %c",binary[7 - z]);
            }
            else if (binary[7 - z] =='0')
            {
                printf("\U000026AB %c",binary[7 - z]);
            }
            else
            {
               printf("\U000026AB %c",binary[7 - z]);
            }
        }
        printf("\n");
    }
}

    // an array to store the binary value
    /*
    char binary[] = {};
    int n = 0;
    //conversion from decimal to binary by dividing by 2
    int dec = total[n];
    for (int i = 1; dec != 0; i++)
    {
        if ((dec % 2) == 0)
        {
            binary[i] = '0';
        }
        else if ((dec % 2) == 1) {
            binary[i] = '1';
        }
            dec = dec / 2;
            n++;
    }


    printf("%i\n",n);

    for (int i = 0; i < n; i++)
    {
        if (binary[n - i] == '1')
        {
            printf("\U0001F7E1");
        }
        else if (binary[n - i] =='0')
        {

            printf("\U000026AB");





    for (int i = 0; i < 50; i++)
    {
        if (binary[i] == '0')
        {
            printf("\U000026AB");
        }
        else if (binary[i] == '1')
        {
            printf("\U0001F7E1");
        }
    }
      if (text[j] == c[i])
        {
            total[j] = b[i];
            //printf("%i\n ",total[j]);
            j++;
            i = -1;

        }
    */
    //printf("\n");


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
/*
char dec_to_bin(int dec)
{
    char binary[3] = {};
    int s = 3;
    //long bin
    for (int i = 0; i < 3; i++)
    {

    for (int i = 0; i < 4; i++)
    {
        if (binary[i] == '0')
        {
            printf("\U000026AB");
        }
        else if (binary[i] == '1')
        {
            printf("\U0001F7E1");
        }

    }

    for (int i = 1; dec != 0; i++)
    {
        if ((dec % 2) == 0)
        {
            binary[s- i] = '0';
        }
        else {
            binary[s- i] = '1';

        }
        dec = dec / 2;
    }
    for (int i = 0; i < 4; i++)
    {
        if (binary[i] == '0')
        {
            printf("\U000026AB");
        }
        else if (binary[i] == '1')
        {
            printf("\U0001F7E1");
        }

    }
        printf("\n");
    return 0;
}
    */


