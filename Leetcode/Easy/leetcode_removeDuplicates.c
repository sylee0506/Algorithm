//It doesn't matter what you leave beyond the returned length

int removeDuplicates(int* nums, int numsSize) {
	int i;
	int index = 1;

	if (numsSize == 0 || numsSize == 1)
		return numsSize;

	for (i = 1; i < numsSize; i++)
	{
		if (nums[i] == nums[i - 1])
			continue;
		else
		{
			nums[index] = nums[i];
			index += 1;
		}
	}

	return index;
}