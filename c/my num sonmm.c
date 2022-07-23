#include<stdio.h>

int main()
{int a=0,b=1,c=0,n,e;
printf("enter the max  ");
scanf("%d",&n);
for (int x=0;x<=n;x++)
{ c=a+b;
a=b;
b=c;
printf("%d\n",c);
}
return 0;
}