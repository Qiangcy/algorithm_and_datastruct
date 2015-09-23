int removeElement1(int* nums, int numsSize, int val) {
    int i, j;
    for(i=0; i<numsSize; ++i) {
        if(nums[i] == val) {
            for(j=i+1; j<numsSize; ++j)
                nums[j-1] = nums[j];
            --numsSize;
            --i;
        }
    }
    if(numsSize==1 && nums[0]==val)
        --numsSize;
    return numsSize;
}

int removeElement2(int* nums, int numsSize, int val) {
    int i, begin = 0;
    for(i=0; i<numsSize; ++i) {
        if(nums[i] != val)
            nums[begin++] = nums[i];
    }
    return begin;
}

int removeElement(int A[], int n, int elem) {
    int begin=0;
    for(int i=0;i<n;i++) if(A[i]!=elem) A[begin++]=A[i];
    return begin;
}
