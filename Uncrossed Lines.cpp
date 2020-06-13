class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int r = A.size();
        int c = B.size();
        
        int **dp = new int*[r+1];
        for(int i=0; i<r+1; i++)
        {
            dp[i]=new int[c+1];
            for(int j=0; j<c+1; j++)
            {
                dp[i][j]=0;
            }
        }
        
            
        for(int i=r-1; i>=0; i--)
        {
            for(int j=c-1; j>=0; j--)
            {
                dp[i][j]= (A[i]==B[j] ? 1 + dp[i+1][j+1] : max(dp[i][j+1] , dp[i+1][j]));
            }
        }
        return dp[0][0];
        
    }
};
