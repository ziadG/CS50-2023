#include <cs50.h>
#include <stdio.h>

int main(void){
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");
    long phone = get_long("What's your phone number? ");


    printf("Your name is %s \n ", name);
    printf("You are %i years old \n ", age);
    printf("You phone number is %li \n ", phone);

}
