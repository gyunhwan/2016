#include <stdio.h>
#include <string.h>

struct People
{
    char name[20]; // data member
    int age;
};

void SetName(People* p, const char* n)
{
    strcpy((*p).name, n);
}

void SetAge(People* p, int a)
{
    (*p).age = a;
}

void Print(People* p)
{
    printf("%s, age=%i\r\n", (*p).name, (*p).age);
}

void main()
{
    People i;
    //strcpy(i.name, "Jintaeks"); // . member access operator
    SetName(&i, "Jintaeks");

    //i.age = 50;
    SetAge(&i, 50);

    //printf("%s, age=%i\r\n", i.name, i.age);
    Print(&i);
}