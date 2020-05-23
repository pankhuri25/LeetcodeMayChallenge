static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        vector<int> first_col(N+1,0);
        //unordered_map<int,int> mp;
        vector<int> save(N+1,0);
        
        for(int i=0; i<trust.size(); i++)
        {
            first_col[trust[i][0]]++;
            save[trust[i][1]]++;
        }
        int temp =-1;
        for(int i=1; i<=N; i++)
        {
            if(first_col[i]==0 && save[i]==N-1)
                temp=i;
        }
        return temp;
    }
};
