class Solution {
public:
    vector<int> countBits(int num) 
    {
        int flag = 2;
        vector<int> ans = {0};
        for (int i = 1; i <= num; i++)
        {
            if (i >= flag)
                flag *= 2;
            
            ans.push_back(ans[i - flag/2] + 1);
        }
        return ans;
    }
};
