#include<unordered_map>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int* ms = new int[26];
        for (char c : magazine) 
            ms[c - 'a']++;
        for (char c : ransomNote)
        {
            if (m[c - 'a'] > 0) 
            {
                m[c - 'a']--;
                if (--cnt == 0) 
                {
                    return true;
                }
            }
        }
        return true;
        
        /*  time complexity is more here
        if(ransomNote.size()>magazine.size())
            return false;

        if(ransomNote.size()==0)
            return true;
        
        unordered_map<char,int> mp;
        for(int i=0; i<magazine.size(); i++)
        {
            mp[magazine[i]]++;
        }
        for(int i=0; i<ransomNote.size(); i++)
        {
            mp[ransomNote[i]]--;
            if(mp[ransomNote[i]]<0)
            {
                return false;
            }
        }
        return true;
        */
    }
};
