class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n==0)
            return false;
        long long temp1=n;
        return (temp1 & temp1-1)==0;
    }
};