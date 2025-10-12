#include <cs50.h>
#include <stdio.h>

int main (void){
    int s;
    int e;

    do {
        s = get_int("how many llamas do you have? ");
        e = get_int("how many llamas will you end up with? ");

    }
    while (s < 9 || e <= s);

    int years = 0;

    while (s < e){

        s = s + s/3 - s/4;
        years++;


    }
    printf("Years: %i \n", years);


    }
