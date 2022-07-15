class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        long long temp1=n;
        long long temp=temp1-1;
        
        if(n==0)
            return false;
        return (temp1 & temp)==0;
    }
};