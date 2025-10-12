// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool test1 = false;
    bool test2 = false;
    bool test3 = false;
    bool test4 = false;
    int length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i]))
        {
            test1 = true;
            //printf("letter %i is uppercase\n",i+1);
        }
        if (islower(password[i]))
        {
            test2 = true;
            //printf("letter %i is lowercase\n",i+1);
        }
        if (isalnum(password[i]) == false)
        {
            test3 = true;
            //printf("letter %i is a symbol\n",i+1);
        }
        if (isdigit(password[i]))
        {
            test4 = true;
        }
    }
    if (test1 == 1 && test2 == 1 && test3 == 1 && test4 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;

}
