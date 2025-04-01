class Solution {
public:
//   int helper(string& s1,string& s2, int i,int j,vector<vector<int>> &dp)
//   {
//     if(i<0)
//     return j+1;
//     if(j<0)return i+1;
//     if(dp[i][j]!=-1)return dp[i][j];

//     if(s1[i]==s2[j])return 0+helper(s1,s2,i-1,j-1,dp);
//     else
//     return 1+min(helper(s1,s2,i,j-1,dp),min(helper(s1,s2,i-1,j,dp),helper(s1,s2,i-1,j-1,dp)));
//   }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(word1,word2,n-1,m-1,dp);

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

         for(int i=0;i<=n;i++)
         {
            dp[i][0]=i;
         }
         for(int j=0;j<=m;j++)
         {
            dp[0][j]=j;
         }
         for(int i=1;i<=n;i++)
         {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
         }
         return dp[n][m];
        
    }
};