class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> a(numRows);
            if(numRows >= 1) {
                a[0].push_back(1);
                if(numRows >= 2) {
                    a[1].push_back(1);
                    a[1].push_back(1);
                    if(numRows >= 3) {
                        a[2].push_back(1);
                        a[2].push_back(2);
                        a[2].push_back(1);
                        for(int i=3; i<numRows; ++i) {
                            auto it = begin(a[i-1]);
                            a[i].push_back(1);
                            for(; it!=end(a[i-1])-1; ++it) {
                                a[i].push_back(*it + *(it+1));
                            }
                            a[i].push_back(1);
                        }
                    }
                }
            }
            return a;
        }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex+1, 1);
        for(int t=2; t<rowIndex+1; ++t) {
            for(int i=t-1; i>0; --i)
                vec[i] = vec[i-1] + vec[i];
        }
        return vec;
    }
};
