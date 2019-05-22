bool hasAlternatingBits(int n){
    char last_bit = n & 1;
    char now_bit;
    
    n = n >> 1;
    while (n > 0) {
        now_bit = (n & 1);
        n = n >> 1;
        if (now_bit == last_bit)
            return false;
        last_bit = now_bit;
    }
    return true;
}
