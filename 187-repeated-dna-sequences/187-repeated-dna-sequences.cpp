class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string>ans;
        if(s.length()==0 || s.length()<=10)
            return ans;
        map<string,int>map;
        string temp="";
        int i=0;
        for(i=0;i<10;i++)
        {
            temp.push_back(s[i]);
        }
        map[temp]=1;
        for(;i<s.size();i++)
        {
            temp.erase(0,1);
            temp.push_back(s[i]);
            if(map.find(temp)==map.end())
                map[temp]=1;
            else
                map[temp]++;
        }
        priority_queue<pair<int,string>>maxHeap;
        for(auto i:map)
            maxHeap.push({i.second,i.first});
        int top=maxHeap.top().first;
        if(top==1)
            return ans;
        while(maxHeap.size()>0 && maxHeap.top().first==top)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};