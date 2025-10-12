#include<cs50.h>
#include<stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

int main(void)
{

    candidate p;
    p.name = "Ziad";
    p.votes = 100;
    printf("Name: %s\n",p.name);


}