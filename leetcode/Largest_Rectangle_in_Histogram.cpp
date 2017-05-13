class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            if(!heights.size())
                return 0;
            if(heights.size() == 1)
                return heights[0];

            int res = 0;
            vector<int>::iterator it = begin(heights);
            for(; it!=end(heights); ++it) {
                int cnt = 1, sum = 0;
                vector<int>::iterator back=it,  head=it;
                while(*it < *(head+1)) {
                    ++head;
                    if(head == end(heights)-1) {
                        if(*it < *(head))
                            ++cnt;
                        break;
                    }
                    ++cnt;
                }
                while(*it < *(back-1)) {
                    --back;
                    if(back == begin(heights)) {
                        if(*it < *back)
                            ++cnt;
                        break;
                    }
                    ++cnt;
                }
                sum = cnt * (*it);
                if(sum > res)
                    res = sum;
            }
            return res;
        }
};
