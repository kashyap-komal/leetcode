class Solution {
public:
  int lcs(string s,string t)
  {
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
      dp[0][i]=0;
    }
    for(int id1=1;id1<=n;id1++)
    {
        for(int id2=1;id2<=m;id2++)
        {
            if(s[id1-1]==t[id2-1])
             dp[id1][id2]=1+dp[id1-1][id2-1];
            else
           dp[id1][id2]=max(dp[id1-1][id2],dp[id1][id2-1]);
        }
    }
    return dp[n][m];
  }
    int longestPalindromeSubseq(string s) {
        string t= s;
        reverse(s.begin(),s.end());
        return lcs(s,t);
        
    }
};