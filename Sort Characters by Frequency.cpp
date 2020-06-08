ss Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(char c : s)
        {
            mp[c]++;
        }
        vector<pair<int, char>> p;
        for(int i = 0; i < 128; i++) 
        {
            if(mp[i] > 0)
            {
                p.push_back({mp[i], i});
            }
        }
        //reverse sort (descending)
        sort(p.rbegin(), p.rend());
        
        string ans;
        for(pair<int, char> r: p) {
            ans.append(r.first, r.second);
            //appends the char first(int) no. of times
        }        
        return ans;
    }
};
