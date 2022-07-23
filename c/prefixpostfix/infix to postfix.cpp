#include<stdio.h>

char stack[20];
int top = -1;

void empiler(char x)
{
    stack[++top] = x;
}
 
char depiler()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
main()
{
    char exp[20];
    char *e, x;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            empiler(*e);
        else if(*e == ')')
        {
            while((x = depiler()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",depiler());
            empiler(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",depiler());
    }
}