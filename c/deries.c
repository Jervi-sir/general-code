int suit(int n)
{
	if (n==0) return 0;
	else if (n==1) return 1;
	      else return suit(n-1)+suit(n-2);
	      
}

int main ()
{ int n;
n=15;
printf("%d",suit(n));
}