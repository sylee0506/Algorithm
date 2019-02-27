int maxSubArray(int* nums, int numsSize) {
	int i;
	int sum = nums[0];
	int max = sum;

	for (i = 1; i < numsSize; i++)
	{
		if (sum + nums[i] > nums[i])
			sum += nums[i];
		else
			sum = nums[i];

		if (sum > max)
			max = sum;
	}
	return max;
}