class Solution {
public:
  
    void dfs(vector<int> &v,vector<int> adj[],int s,bool &flag,vector<int> &type)
    {
        v[s] = 1;
        for(int i:adj[s])
        {
            if(v[i]==0)
            {
                type[i] = !(type[s]);
                dfs(v,adj,i,flag,type);
            }
            else
            {
                if(type[i] ==  type[s])
                {
                    flag=false;
                    return;
                }
            }
        }
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& d) {
        if(d.size()==0)
            return true;
        vector<int> adj[N+1];
        for(int i=0;i<d.size();i++)
            adj[d[i][0]].push_back(d[i][1]),adj[d[i][1]].push_back(d[i][0]);
        vector<int> v(N+1,0),type(N+1,0);
        bool flag;
        
        type[1] = 0;
        
        for(int i=1;i<=N;i++)
        {
            flag=true;
            if(v[i]==0)
            {
                dfs(v,adj,i,flag,type);
                if(!flag)
                    return false;
            }
        }
        return true;
    }
};
