class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        if(m==0)
            return (n==0);
        bool lookup[n+1][m+1];
        memset(lookup,false,sizeof(lookup));
        lookup[0][0]=true;
        for(int j=1;j<=m;j++)
            if(p[j-1]=='*')
                lookup[0][j]=lookup[0][j-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='*')
                    lookup[i][j]=lookup[i][j-1] || lookup[i-1][j];
                else if(p[j-1]=='?' || s[i-1]==p[j-1])
                    lookup[i][j]=lookup[i-1][j-1];
                else
                    lookup[i][j]=false;
            }
        }
        return lookup[n][m];
    }
};