class Solution {
public
    int uniquePathsWithObstacles(vectorvectorint& obstacleGrid) {
        if (obstacleGrid.empty()  obstacleGrid[0].empty()  obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vectorvectorlong long dp(n+1,vectorlong long(m+1,0));
        dp[1][0]= 1;
        for(int i = 1;i = n;i++) {
            for(int j = 1;j = m;j++) {
                if(obstacleGrid[i-1][j-1] == 1) {
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};