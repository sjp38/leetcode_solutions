bool repeatedSubstringPattern(char* s) {
	int i, j;
	int len;
	bool no_copy;

	len = strnlen(s, 10000);

	for (i = 1; i <= len / 2; i++) {
		if (len % i)
			continue;
		no_copy = false;
		for (j = i; j <= len - i; j += i) {
			if (strncmp(s, &s[j], i)) {
				no_copy = true;
				break;
			}
		}
		if (!no_copy)
			return true;
	}
	return false;
}
