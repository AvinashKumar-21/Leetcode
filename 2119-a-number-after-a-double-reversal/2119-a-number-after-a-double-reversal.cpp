class Solution {
public:
    int fun(int num)
    {
        int ans=0;
        while(num)
        {
            int temp=num%10;
            num=num/10;
            ans=ans*10+temp;
        }
        return ans;
    }
    bool isSameAfterReversals(int num) 
    {
        return fun(fun(num))==num;
    }
};