

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *ret;
    int idx = 0;
    int i, j, k;
    bool dup;
    ret = (int *)malloc(sizeof(int) * nums1Size);
    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            if (nums1[i] != nums2[j])
                continue;
            for (dup = false, k = 0; k < idx; k++) {
                if (ret[k] == nums1[i]) {
                    dup = true;
                    break;
                }
            }
            if (dup)
                continue;
            ret[idx++] = nums1[i];
        }
    }
    *returnSize = idx;
    return ret;
}
