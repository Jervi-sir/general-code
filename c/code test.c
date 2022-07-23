#include <stdio.h>
int main()
{int i,code;
for (i=1; i<=3 ; i++)
{printf("enter your code");
scanf("%d",&code);

/*if enter right code*/
if (code == 175) break;
}
printf("welcome");
return 0;
}