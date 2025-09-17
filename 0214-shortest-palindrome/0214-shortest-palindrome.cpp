class Solution {
public:
    string shortestPalindrome(string s) {
        string reversestring=s;
        reverse(reversestring.begin(),reversestring.end());
        for(int i=0;i,s.size();i++)
        {
            if(!memcmp(s.c_str(),reversestring.c_str()+i,s.size()-i))
            {
                return reversestring.substr(0,i)+s;
            }
        }
        return reversestring+s;
    }
};