#include<cstring>
#include<unordered_map>
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count=0;
        unordered_map <char,bool> map;
        for(int i=0; i<J.length(); i++)
        {
            map[J[i]]=1;
        }
        for(int i=0; i<S.length(); i++)
        {
            if(map[S[i]])
            {
                count++;
            }
        }
        return count;
    }
};
