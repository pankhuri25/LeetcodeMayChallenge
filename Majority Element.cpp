class Solution {
public:
    
    Solution() {
        ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    }
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums)
        {
            mp[i]++;
        }
        int maximum=mp[nums[0]];
        int maxx=nums[0];
        for(int i =0; i<nums.size(); i++)
        {
            if(mp[nums[i]]>maximum)
            {
                maximum=mp[nums[i]];
                maxx=nums[i];
            }
        }
        return maxx;
    }
};
