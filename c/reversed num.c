#include <stdio.h>

int rev(int n)
{
	int reverse = 0;
	while (n != 0)
	{
		reverse = reverse * 10;
		reverse = reverse + n % 10;
		n = n / 10;
	}

	return reverse;
}

int main()
{
	int i, b;
	for (i = 1; i < 1000000; i++)
	{  b=rev(i)*i;
		if (rev(b) == b)
			printf("%d   %d   %d \n",b,rev(i), i);
	}
}