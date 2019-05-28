int reverse(int x){
    long val = x;
    long max = INT_MAX;
    long reversed = 0;
    bool is_minus = false;
    
    if (x < 0) {
        val = (long)x * -1;
        is_minus = true;
        max = (long)INT_MIN * -1;
    }
    while (val) {
        reversed = reversed * 10 + val % 10;
        if (reversed >= max)
            return 0;
        val = val / 10;
    }
    if (is_minus)
        reversed *= -1;
    return reversed;
}
