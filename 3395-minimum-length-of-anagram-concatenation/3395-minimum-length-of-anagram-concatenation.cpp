class Solution {
public:
    bool f(string s,int len)
    {
        string temp=s.substr(0,len);
        sort(temp.begin(),temp.end());
        for(int i=len;i<s.size();i=i+len)
        {
            string str=s.substr(i,len);
            sort(str.begin(),str.end());
            if(temp!=str)
            {
                return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=1;i<=s.size();i++)
        {
            if(n%i==0)
            {
                if(f(s,i))
                return i;
            }
        }
        return s.size();
        
    }
};