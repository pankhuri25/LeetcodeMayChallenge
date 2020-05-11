class Solution {
public:
    int findComplement(int num) {
        
        if(num==0) 
            return 1;
        int ans=0;
        int b = num;
        while(b!=0)
        {
            b=b/2;
            ans++;
        }
        int a = pow(2,ans)-1;
        
        return a^num;
       
    }
};
