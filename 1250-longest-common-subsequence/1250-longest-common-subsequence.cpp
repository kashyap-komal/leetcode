class Solution {
public:
//    int helper(int id1,int id2,string text1,string text2,vector<vector<int>> &dp)
//    {
//     //base case
//     if(id1<0 || id2<0)
//     return 0;
//     if(dp[id1][id2]!=-1)return dp[id1][id2];
//     if(text1[id1]==text2[id2])
//     return dp[id1][id2]=1+helper(id1-1,id2-1,text1,text2,dp);

//     else
//     return dp[id1][id2]=0+ max(helper(id1-1,id2,text1,text2,dp),helper(id1,id2-1,text1,text2,dp));
//    }
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(n-1,m-1,text1,text2,dp);




      // tabulation is below code 
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    //Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (text1[ind1 - 1] == text2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; 

       

        
    }
};