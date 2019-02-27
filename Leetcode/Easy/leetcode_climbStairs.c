int climbStairs(int n) {
	if (n == 1 || n == 2)
		return n;

	return climbStairs(n - 1) + climbStairs(n - 2);
}

/*
c much faster code) not recursive
int climbStairs(int n)
{
	long int a = 1, b = 1;
	while(n--)
	{
		b += a;
		a = b - a;
	}
	return a;
}
*/