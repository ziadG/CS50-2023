#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Converting input to lower case
int score_calc(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word);i++)
    {
        if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 'a'];
        }
        else if (isupper(word[i]))
        {
            score = score + POINTS[word[i] - 'A'];
        }        
        
    }    
    return score;
}

int to_lower(string word)
{
    for (int i = 0; word[i] >= 65 && word[i] <= 122; i++)
        {
            if (islower(word[i]))
            {
                break;
            }
            else if (word[i] < 65 || word[i] > 122)
            {
                word[i] = '\0';
            }
            
        word[i] = word[i] + 32;
    }    
}

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int score1 = score_calc(word1);
    int score2 = score_calc(word2);
    
    to_lower(word1);
    //printf("Word1: %s\n",word1);
    to_lower(word2);
    // Removing non - alphabetical characters
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else 
    {
        printf ("Player 2 Wins\n");
    }   
}
