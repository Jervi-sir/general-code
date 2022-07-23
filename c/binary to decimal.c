#include<stdio.h>

void main()
{
	int i;
long num, decimal_num, remainder, base = 1, binary = 0;

printf("Enter a decimal integer \n");
scanf("%d", &num);
for ( i =0; i<= num; i++);
{
decimal_num = i;
while (i > 0)
{
  remainder = num % 2;
  binary += remainder * base;
  i /= 2;
  base *= 10;
}
printf("Input number is = %d\n", decimal_num);
printf("Its binary equivalent is = %d\n", binary);
}
return 0;
}
