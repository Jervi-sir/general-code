#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int LOW = 1;
const int HIGH = 320;

int main()
{
    int ranr, i;
    int a,x;
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);

            ranr = rand() % (HIGH - LOW + 1) + LOW;
         for (int i=10;i>1;i--)
           {   printf("\n\n____%%________\n");
               printf("%d chanse left\n",i);
               printf("guess\n");
               scanf("%d",&x);
               printf("\n");
        	if (x<ranr) printf("higher\n");
          	else if (x>ranr) printf("smaller\n");
             	     else {printf("true\n");                                           a =1;break;}
           }
           if (a==1) printf("fuckyo u beat me");
            else printf("the true %d bitdh",ranr);
        return 0;
}