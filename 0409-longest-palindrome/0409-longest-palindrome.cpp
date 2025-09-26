class Solution {
public:
    int longestPalindrome(string s) {
        int alpha[128]={0};
        for(char c:s)
        {
            alpha[c]++;
        }
        int pallength=0;
        for(int freq:alpha)
        {
            pallength+=(freq/2)*2;
        }
        if(pallength<s.size())
        {
            pallength+=1;
        }
        return pallength;
        
    }
};