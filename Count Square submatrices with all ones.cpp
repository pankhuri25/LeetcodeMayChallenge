class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int> > dp;
        
        dp.assign(n+1, vector<int>(m+1,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==1)
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1]))+1;
                ans += dp[i+1][j+1];
            }
        }
        return ans;
        
        /*
        int ans=0;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(i>0 && j>0 && matrix[i][j]>0)
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j],matrix[i][j-1])) + 1;
                
                ans +=matrix[i][j];
            }
        }
        return ans;
        */
    }
};
