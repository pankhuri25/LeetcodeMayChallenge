class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
        
        int res = 0;
        auto k = 1;
        while(num > 0)
        {
            int bit = num % 2;
            res += (bit == 1 ? 0 : 1)*k;
            k *= 2;
            
            num /= 2;
        }
        
        return res;
       }
};
