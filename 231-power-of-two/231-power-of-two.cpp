class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        long long temp1=n;
        if(n==0)
            return false;
        return (temp1 & temp1-1)==0;
    }
};