class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini=INT_MAX;
        vector<vector<int>>res;
        int n=arr.size();
        sort(arr.begin(),arr.end());

        for(int i=0;i<n-1;i++)
        {
            mini = min(mini, arr[i + 1] - arr[i]);
        }
        for(int j=0;j<n-1;j++)
        {
            if(arr[j+1]-arr[j]==mini)
            res.push_back({arr[j],arr[j+1]});
        }
        return res;

    }
};