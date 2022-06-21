class Solution {
public:
    string convert(string s, int n) 
    {
        if(n==1)
            return s;
        vector<string>temp(n);
        for(int i=0;i<s.size();)
        {
            for(int j=0; j<n-1 && i<s.size();j++)
                temp[j].push_back(s[i++]);
            for(int j=n-1; j>0 && i<s.size();j--)
                temp[j].push_back(s[i++]);
        }
        string ans="";
        for(auto i:temp)
            ans.append(i);
        return ans;
    }
};