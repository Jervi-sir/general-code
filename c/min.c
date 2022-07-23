#include<stdio.h>

int main()
{int x,pp,n;
printf("entre n=   ");
scanf("%d",&n);
pp=n;
for(int i=1 ; i <=3 ; i++)
{
printf("entre n=   ");
scanf("%d",&n);
if (n>=pp) pp=pp;
else pp=n;
}
printf("smallest is %d",pp);
return 0;
} 