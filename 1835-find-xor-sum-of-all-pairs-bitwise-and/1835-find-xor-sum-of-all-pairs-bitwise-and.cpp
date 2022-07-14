class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int a=0;
        int b=0;
        for(auto i:arr1)
            a=a^i;
        for(auto i:arr2)
            b=b^i;
        return a&b;
    }
};