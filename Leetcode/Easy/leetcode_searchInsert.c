int searchInsert(int* nums, int numsSize, int target) {
	int i;
	int left = 0, right = numsSize - 1, middle;

	//binary search
	while (left <= right)
	{
		middle = (left + right) / 2;

		if (target == nums[middle])
			return middle;
		else if (target > nums[middle])
			left = middle + 1;
		else if (target < nums[middle])
			right = middle - 1;
	}

	if (nums[middle] < target)
		return middle + 1;
	else
		return middle;
}