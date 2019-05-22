bool hasAlternatingBits(int n){
    char last_bit = -1;
    char now_bit;
    
    while (n > 0) {
        now_bit = (n & 1);
        n = n >> 1;
        if (last_bit == -1) {
            last_bit = now_bit;
            continue;
        }
        if (now_bit == last_bit)
            return false;
        last_bit = now_bit;
    }
    return true;
}
