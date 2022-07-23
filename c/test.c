int loop(int a,int b)
{if (b>0) return loop(a-1,b-1);
else return a;
}

main ()
{
	int a,b;
	a=6;
	b=3;
	loop(a,b);
}