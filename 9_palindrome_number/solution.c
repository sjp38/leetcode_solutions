bool isPalindrome(int x){
    int origin = x;
    long reversed = 0;
    
    if (x < 0)
        return false;
    
    while (x) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    if (reversed == origin)
        return true;
    return false;
}
