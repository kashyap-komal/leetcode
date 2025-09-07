class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>mp;
        //map to count and store occurence of each element
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        while(!mp.empty())
        {
            int currentcard=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
               if(mp[currentcard+i]==0)
               {
                return false;
               } 
               mp[currentcard+i]--;
               if(mp[currentcard+i]<1)
               {
                mp.erase(currentcard+i);
               }
            }
        }
        return true;
        
    }
};