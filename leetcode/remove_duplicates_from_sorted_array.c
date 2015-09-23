int removeDuplicates_first(int* nums, int numsSize) {
    int i, j, k;
    for(i=0; i<numsSize; ++i) {
        j = i + 1;
        while(nums[i]==nums[j] && j<numsSize) {
            ++j;
        }
        if(j == numsSize)
            return j-i+1;
        k = i + 1;
        while(k != j)
            nums[k++] = nums[j];
    }
    return i;
}


int removeDuplicates(int* nums, int numsSize) {
    int i=1, j=1;
    if(numsSize == 0)
        return 0;
    while(i < numsSize) {
        while(nums[j]==nums[j-1] && j<numsSize)
            ++j;
        if(j != numsSize)
            nums[i] = nums[j];
        else
            break;
        ++i;
        ++j;
    }
    return i;
}
