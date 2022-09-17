class Solution {
public:
    string makeGood(string s) 
    {
        string ans="";
        if(s.size()==0)
            return ans;
        stack<char>st;
        for(auto i:s)
        {
            if(st.empty())
            {
                st.push(i);
            }   
            else
            {
                char temp=st.top();
                if(i>='a' && i<='z')
                {
                    if(temp+32==i)
                        st.pop();
                    else
                        st.push(i);
                }
                else
                {
                    if(temp-32==i)
                        st.pop();
                    else
                        st.push(i);
                }
            }
        }
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};