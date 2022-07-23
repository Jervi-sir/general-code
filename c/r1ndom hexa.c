#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length;
    char str[] = "0123456789ABCDEF";
    //Seed number for rand() 
    srand((unsigned int) time(0) + getpid());
    length = rand() % 15 + 8;
    while(length--)
        {
            putchar(str[rand() % 16]);
            srand(rand());
        }
    printf("\n");
    return EXIT_SUCCESS;
}