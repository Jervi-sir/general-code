
#include <stdio.h>

int main()
{
  int n,i=10,a,r = 0,j=0;
float y;
  printf("Enter a number to reverse\n");
  scanf("%d",&n);

i-=1;
while (i--)
{
 a=n;
  while (n != 0)
{ ee++;
  r = r * 10;
  r = r + n%10;
  n = n/10;
}

  printf("Reverse of entered number is = %d\n", r);
y=a*r;
printf("multiplication=%d\n",y);
  return 0;
}
}