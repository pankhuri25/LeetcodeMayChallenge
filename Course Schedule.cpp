class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return true;

        vector<int> edge[numCourses];
        vector<int> deg(numCourses, 0);  
        int count = 0;        

        for (vector<int> pair : prerequisites)
        {
            edge[pair[1]].push_back(pair[0]);
            deg[pair[0]]++;
        }

        queue<int> Q;

        for (int i = 0; i < numCourses; i++)
        {
            if (deg[i] == 0)
            {
                Q.push(i);
                count++;
            }
        }

        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (int v : edge[u])
            {
                deg[v]--;
                if (deg[v] == 0)
                {
                    count++;
                    Q.push(v);
                }
            }
        }

        return (count == numCourses);  
    }
};
