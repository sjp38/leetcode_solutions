// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned left, right;
    int mid;
    
    for (left = 1, right = n; ;) {
        mid = (left + right) / 2;
        if ((mid == 1 || !isBadVersion(mid - 1)) && isBadVersion(mid))
            return mid;
        if (!isBadVersion(mid) && (mid == n - 1 || isBadVersion(mid + 1)))
            return mid + 1;
        if (isBadVersion(mid))
            right = mid;
        else
            left = mid;
    }
    return mid + 1;
}
