class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> output;
        int i=0;
        int j=0;
        
        while(i<A.size() && j<B.size())
        {
            int low=max(A[i][0], B[j][0]);
            int high=min(A[i][1], B[j][1]);
            
            if(low<=high)
                output.push_back({low,high});
            
            if(A[i][1] < B[j][1]) 
                i++;
            else
                j++;
        }
        return output;
    }
};
