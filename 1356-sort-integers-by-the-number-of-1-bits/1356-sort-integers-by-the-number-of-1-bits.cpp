class Solution {
public:
    map<int,multiset<int>>m;
    void fun(int n)
    {
        int count=0;
        int temp=n;
        while(temp)
        {
            temp=temp&(temp-1);
                count++;
        }
        m[count].insert(n);
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            fun(arr[i]);
        }
        for(auto i:m)
        {
            for(auto j:i.second)
                ans.push_back(j);
        }
        return ans;
    }
};