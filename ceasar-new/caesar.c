#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//𝑐𝑖=(𝑝𝑖+𝑘)⁢ % ⁢26
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    printf("argc: %i\n",argc);
    printf("argv: %s\n",argv[1]);
    for (int i = 0; i < strlen(argv[1]); i++)
    {   
        int c = argv[1][i];
        if (c >= 65 && c <= 122)
        {
            printf("Usage: ./caesar\n");
            //printf("argv: %s\n",argv[1]);
            return 1;
        }
        printf("num: %i\n",key);
    }
    string text = get_string("Plaintext: ");
    for (int j =0; j < strlen(text);j++)
    {
        int b = 0;
        if (isalpha(text[j]) && isupper(text[j]))
        {
            b = (text[j] - 65 + key) % 26;
            text[j] = b + 65;
        }
        else if ((isalpha(text[j]) && islower(text[j])))
        {
            b = (text[j] - 97 + key) % 26;
            text[j] = b + 97;
        }           
    }
    printf("ciphertext: %s\n",text);
    return 0;
}