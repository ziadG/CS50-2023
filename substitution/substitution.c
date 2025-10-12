#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// argv is the key...
char cipher(char c, string key);

int main(int argc, string argv[])
{
    // requiring a single command line arg.
    if (argc > 2 || argc == 1)
    {
        printf("Enter a single key\n");
        return 1;
    }
    // checking the length
    else if (strlen(argv[1]) < 26)
    {
        printf("Your key must be 26 characters long.\n");
        return 1;
    }
    // checking for each letter
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("Your key must be alphabetical only.\n");
            return 1;
        }
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Your key must not contain any special characters.\n");
            return 1;
        }
    }
    // checking for duplicates through nested loops
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("You've repeated the character %c at the position %i.\n", argv[1][i], j);
                return 1;
            }
        }
    }
    // getting plain text from user
    string plain = get_string("plaintext: ");

    printf("ciphertext: ");
    int length = strlen(plain);
    for (int i = 0; i < length; i++)
    {
        printf("%c", cipher(plain[i], argv[1]));
        // printf("%c",plain[i]);
    }
    printf("\n");
    return 0;
}

char cipher(char c, string key)
{
    int position = 0;
    // if it's a char return it as it is
    if (isalpha(c) == 0)
    {
        return c;
    }
    // keep every upper / lower case as it is
    else if (isupper(c))
    {
        position = c - 65;
        c = toupper(key[position]);
        return c;
    }
    else if (islower(c))
    {
        position = c - 97;
        c = tolower(key[position]);
        return c;
    }
    return 0;
}
