#include<stdio.h>
#include<string.h>
#include<iostream>
struct Student
{
    int sid;
    char name[200];
    int age;
};

int main ()
{
    struct Student st={1000,"zhang",20};
    struct Student *pst;
    pst=&st;
    pst->sid=91; //(*pst).sid;
    

    return 0;
}