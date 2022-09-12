class Solution {
public:
    string addBinary(string a, string b) 
    {
        int c=0;
        string s="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0;
        for(i=0,j=0;i<a.size() && j<b.size();i++,j++)
        {
            int temp=(int(a[i])-48)+(int(b[j])-48)+c;
            c=temp/2;
            temp=temp%2;
            s.append(to_string(temp));
        }
        for(i;i<a.size();i++)
        {
            int temp=int(a[i])+c-48;
            c=temp/2;
            temp=temp%2;
            s.append(to_string(temp));
        }
        for(j;j<b.size();j++)
        {
            int temp=int(b[j])+c-48;
            c=temp/2;
            temp=temp%2;
            s.append(to_string(temp));
        }
        if(c)
        s.append(to_string(c));
        reverse(s.begin(),s.end());
        return s;
    }
};