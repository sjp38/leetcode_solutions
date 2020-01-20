bool valid(int a, int b)
{
    if (b <= 0.5 * a + 7)
        return false;
    if (b > a)
        return false;
    if (b > 100 && a < 100)
        return false;
    return true;
}

int numFriendRequests(int* ages, int agesSize){
    int i, j;
    int a, b;
    int answer = 0;
    int count[120] = {0,};
    
    for (i = 0; i < agesSize; i++)
        count[ages[i] - 1]++;
    
    for (i = 0; i < 120; i++) {
        for (j = 0; j < 120; j++) {
            if (valid(i + 1, j + 1)) {
                if (!count[i] || !count[j])
                    continue;
                a = count[i];
                b = count[j];
                if (i == j)
                    b--;
                answer += a * b;
            }
        }
    }
    return answer;
}
