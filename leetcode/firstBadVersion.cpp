// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return check(1, n);
    }
private:
    int check(int start, int end) {
        if(start == end)
            return start;
        int half = start+(end-start)/2;
        if(isBadVersion(half))
            return check(start, half);
        else
            return check(half+1, end);
    }
};


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while(start != end) {
            /* int half = (start+end)/2; */
            int half = start+(end-start)/2;
            if(isBadVersion(half))
                end = half;
            else
                start = half+1;
        }
        return start;
    }
};
