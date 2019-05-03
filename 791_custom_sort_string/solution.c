char *order_str;

static inline int orderof(char c) {
	int i;

	for (i = 0; i < 26 && order_str[i] != '\0'; i++) {
		if (c == order_str[i])
			return i;
	}
	return 0;
}

int cmp(void *l, void *r) {
	int il, ir;

	il = orderof(*(char *)l);
	ir = orderof(*(char *)r);

	return il - ir;
}

char * customSortString(char * S, char * T){
	order_str = S;

	qsort(T, sizeof(char) * strnlen(T, 200), sizeof(char), cmp);

	return T;
}
