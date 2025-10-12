#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string text);
char rotate(char c, int n);
// argv[1] is the key...
int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc > 2 || argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if ((only_digits(argv[1])) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int num = atoi(argv[1]);

    // Prompt user for plaintext
    string plain = get_string("Plaintext: ");
    int len = strlen(plain);

    // For each character in the plaintext:
    printf("Ciphertext: ");
    // cinversion to start from 0

    for (int i = 0; i < len; i++)

    {
        printf("%c", rotate(plain[i], num));
    }
    printf("\n");
    // Rotate the character if it's a letter
    return 0;
}

bool only_digits(string text)
{
    int length = strlen(text);
    bool result;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(text[i]))
        {
            result = true;
        }
        else
        {
            return false;
        }
    }
    return result;
}
char rotate(char c, int n)
{
    char rot = 0;
    if (isalpha(c) == 0)
    {
        return c;
    }
    else if (islower(c))
    {
        rot = ((c - 97 + n) % 26) + 97;
        // printf("%c",rot);
    }
    else if (isupper(c))
    {
        rot = ((c - 65 + n) % 26) + 65;
        // printf("%c",rot);
    }
    return rot;
}