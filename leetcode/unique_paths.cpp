class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, m*n);

        for(int i=0; i<m; ++i)
            dp[i][0] = 1;
        for(int j=0; j<n; ++j)
            dp[0][j] = 1;
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        /* TLE */
//        for(int i=m-1; i>=0; --i) {
//            for(int j=n-1; j>=0; --j) {
//                if(i==m-1 && j==n-1)
//                    continue;
//                else if(i == m-1)
//                    dp[i][j] = dp[i][j] + dp[i][j+1];
//                else if(j == n-1)
//                    dp[i][j] = dp[i][j] + dp[i+1][j];
//                else
//                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
//            }
//        }
        return dp[m-1][n-1];
    }
};
