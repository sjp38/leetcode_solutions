char shift(unsigned char c, int nr_shifts) {
    int offset = c - 'a';
    offset = (offset + nr_shifts) % 26;
    return 'a' + offset;
}

char * shiftingLetters(char * S, int* shifts, int shiftsSize){
    int i, j;
    for (i = shiftsSize - 2; i >= 0; i--) {
        shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }
    for (i = 0; i < shiftsSize; i++)
        S[i] = shift(S[i], shifts[i]);
    return S;
}
