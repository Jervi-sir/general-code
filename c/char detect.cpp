#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int sss(char *x)
{   int c;
    c = *x - 48;
    if(c<10) {if(c>=0) return 1;}
    else return 0;
}

int main()
{
    char exp[1];
    char *e;
    int c;
    printf("enter \n");
    gets(exp);

    e = exp;

    if(sss(e))  printf("is");
    else printf("not");


 return 0;
}
