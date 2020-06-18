class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> ans;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0; i<K; i++)
        {
            int x = (pow(points[i][0],2) + pow(points[i][1],2));
            pq.push({x,i});
        }
        
        for(int i=K; i<points.size(); i++)
        {
            int x = (pow(points[i][0],2) + pow(points[i][1],2));
            if(x < pq.top().first)
            {
                pq.pop();
                pq.push({x,i});
            }
        }
        while(!pq.empty())
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
        
        
        //approach2
        /*
        nth_element(points.begin(), points.begin() + K, points.end(),[]
        (
            vector<int> &v1, vector<int> &v2)
            {
                return v1[0]*v1[0] + v1[1]*v1[1] < v2[0]*v2[0] + v2[1]*v2[1];
            }
        );
        points.resize(K);
        
        return points;
        */
    }
};
