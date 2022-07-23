#include<stdio.h>

int main()
{
    int i = 1;
    for(i; i <= 100; i++)
    {
        if((i % 3 == 0 && i % 5 == 0))  printf("fizzbuzz\n");
        else if(i % 3 == 0) printf("fizz\n");
                 else if(i % 5 == 0) printf("buzz\n");
                        else    printf("%d\n",i);   
    }
return 0;
}