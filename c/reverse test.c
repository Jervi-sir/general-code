
#include <stdio.h>
int main()
{
	int n, rev = 0, r, o;

	printf("Enter an integer: ");
	scanf("%d", &n);
	o = n;
	while (n != 0)
	{
		r = n % 10;
		rev = reversedInteger * 10 + remainder;
		n /= 10;
	}
	if (originalInteger == reversedInteger)
		printf("%d is a palindrome.", originalInteger);
	else
		printf("%d is not a palindrome.", originalInteger);
	return 0;
}