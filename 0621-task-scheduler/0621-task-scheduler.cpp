class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int size=tasks.size();

        unordered_map<char,int>eleFreq;

        for(int i=0;i<size;i++)
        {
            eleFreq[tasks[i]]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto [key,value]:eleFreq)
        {
            pq.push({value,key});
        }

        int block=pq.top().first-1;

        int space=block*(n);

        int totalInterval=pq.top().first+space;

        pq.pop();

        while(!pq.empty())
        {
            auto [freq,ele]=pq.top();

            pq.pop();

            int fit=min({freq,block,space});   // copies that fit into idle slots

            totalInterval+=freq-fit;           // leftover goes at the end

            space-=fit;
        }

        return totalInterval;
    }
};