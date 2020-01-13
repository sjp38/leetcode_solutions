int cmp_char(const void *l, const void *r)
{
    return *(char *)l - *(char *)r;
}

int get_chksum(char *s, int len)
{
    int sum = 0, i;
    for (i = 0; i < len; i++)
        sum += (int)s[i];
    return sum;
}

bool checkInclusion(char * s1, char * s2){
    int len1, len2;
    int sum, sum2;
    int i;
    char *sorted;
    int diffs;
    
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 > len2)
        return false;
    sum = get_chksum(s1, len1);
    qsort(s1, len1, sizeof(char), cmp_char);
    sorted = (char *)malloc(sizeof(char) * len1);
    for (i = 0; i <= len2 - len1; i++) {
        if (i == 0)
            sum2 = get_chksum(&s2[i], len1);
        else
            sum2 += s2[i + len1 - 1] - s2[i - 1];
        if (sum2 != sum)
            continue;
        memcpy(sorted, &s2[i], sizeof(char) * len1);
        qsort(sorted, len1, sizeof(char), cmp_char);
        if (!strncmp(sorted, s1, len1))
            return true;
    }
    return false;
}
