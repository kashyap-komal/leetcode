class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>arr(26,0);
        for(auto e: tasks)
        arr[e-'A']++;
        priority_queue<int>pq;
        queue<pair<int,int>>q;

        for(auto i:arr)
        {
            if(i>0)
            pq.push(i);
        }
        int time=0;
        while(pq.size()>0 || q.size()>0)
        {
            time++;
            if(q.size()>0 && q.front().second==time)
            {
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.size()>0)
            {
                int remain=pq.top()-1;
                if(remain>0)q.push({remain,time+n+1});
                pq.pop();
            }
        }
        return time;
    }
};