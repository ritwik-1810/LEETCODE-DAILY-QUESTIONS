class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int i=1;

        int size=colors.size();

        int cost=0;

        while(i<size)
        {
            if(colors[i]==colors[i-1])
            {
                priority_queue<int,vector<int>,greater<int>>pq;

                while(i<size && colors[i]==colors[i-1])
                {
                    pq.push(neededTime[i-1]);

                    i++;
                }

                pq.push(neededTime[i-1]);

                while(pq.size()!=1)
                {
                    cost+=pq.top();

                    pq.pop();
                }
            }
            else
            {
                i++;
            }
        }


       return cost;

        
    }
};