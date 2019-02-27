//KMP
int strStr(char* haystack, char* needle) {
	if (!strlen(needle))
		return 0;
	if (strlen(haystack) < strlen(needle))
		return -1;

	int ans = -1;
	int i = 0, j = 0;
	int flag = 0;
	int temp = -1;

	while (i < strlen(haystack) && j < strlen(needle))
	{
		if (strlen(haystack) - i < strlen(needle) - j)
			break;

		if (needle[j] == haystack[i])
		{
			if (flag == 0)
			{
				ans = i;
				flag = 1;
			}
			j++;
		}
		else
		{
			if (flag == 1)
			{
				ans = -1;
				if (temp > 0)
					i = temp - 1;
				j = 0;
				temp = -1;
			}
			flag = 0;
		}

		i++;
		if (haystack[i] == needle[0] && flag && temp < 0)
			temp = i;
	}
	return ans;
}

/*
good c code) brutal force, but using pointer => fast
int strStr(char *haystack, char *needle) {
	char *p, *q;
	int i, len = strlen(haystack) - strlen(needle);

	for (i = 0; i <= len; i++) {
		p = haystack + i;
		q = needle;
		while (*q && *p == *q) {
			++p;
			++q;
		}
		if (*q == 0)
			return i;
	}
	return -1;
}*/