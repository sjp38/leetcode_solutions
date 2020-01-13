void count_chrs(char *s, int len, int *counts)
{
    int i;
    for (i = 0; i < len; i++) {
        counts[s[i] - 'a']++;
    }
}

bool checkInclusion(char * s1, char * s2){
    int len1, len2;
    int i, j;
    int nr_chrs1[26] = {0,};
    int nr_chrs2[26] = {0,};
    
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 > len2)
        return false;
    count_chrs(s1, len1, nr_chrs1);
    for (i = 0; i <= len2 - len1; i++) {
        if (i == 0) {
            count_chrs(&s2[i], len1, nr_chrs2);
        } else {
            nr_chrs2[s2[i + len1 - 1] - 'a']++;
            nr_chrs2[s2[i - 1] - 'a']--;
        }
        for (j = 0; j < 26; j++) {
            if (nr_chrs1[j] != nr_chrs2[j])
                break;
        }
        if (j == 26)
            return true;
    }
    return false;
}
