int mySqrt(int x) {
	if (x == 0 || x == 1)
		return x;

	long int num = 1;

	while (1)
	{
		if (num*num > x)
			return num - 1;
		else
			num += 1;
	}

}

/*
c good code) binary search!
int mySqrt(int x) {
	if (x == 0)
	{
		return 0;
	}
	int left = 1, right = x;
	int mid = (left + right) / 2;
	while (true)
	{
		if (x / mid > mid)
		{
			if ((x / mid - mid) == 1)
			{
				return mid;
			}
			left = mid;
			mid = (left + right) / 2;
		}
		else if (x / mid < mid)
		{
			if ((mid - x / mid) == 1)
			{
				return x / mid;
			}
			right = mid;
			mid = (left + right) / 2;
		}
		else
		{
			return mid;
		}
	}
}
*/