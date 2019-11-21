bool isPowerOfFour(int num){
    while (num > 1) {
        if (num & 3)
            return false;
        num = num >> 2;
    }
    return num == 1;
}
