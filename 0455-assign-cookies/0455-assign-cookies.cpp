class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m= g.size();
        int n=s.size();
        int l=0,r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i< m && l<n;)
        {
            if(s[l]>=g[i])
            {
                i++;
                r++;
            }
            l++;
        }
        return r;


        
    }
};