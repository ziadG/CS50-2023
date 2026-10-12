#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
int sentence (string sentence)
{
    int s = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == '?' || sentence[i] == '!' || sentence[i] == '.')
        {
            s++;    
        }                
    }
    return s;    
}
float letter (string sentence)
{
    int l = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (isalpha(sentence[i]))
        {
            l++;
        }        
    }
    return l;
}
float word (string sentence)
{
    int w = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if ((isspace(sentence[i])))
        {
            w++;
        }        
    }
    w++;
    return w;
}
int main(void)
{
    string sent = get_string("Sentence: \n");
    float L = letter(sent) / word(sent) * 100;
    float S = sentence(sent) / word(sent) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int n = round(index);
    if (n < 0)
    {
        printf("Before Grade 1\n");    
    }
    else if (n > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",n);
    }       
}