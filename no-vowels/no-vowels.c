// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

string replace(string argv[1]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n",replace(argv));
    }
    else
    {
        printf("enter a single word\nm ");
        return 0;
    }

}

string replace(string argv[1])
{
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        switch (argv[1][i])
        {
            case 'a':
                argv[1][i] = '6';
                break;
            case 'e':
                argv[1][i] = '3';
                break;
            case 'o':
                argv[1][i] = '0';
                break;
            case 'i':
                argv[1][i] = '1';
                break;
        }

    }
    return argv[1];



}


