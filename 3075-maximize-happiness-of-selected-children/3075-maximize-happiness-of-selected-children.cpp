class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        int size = happiness.size();

        int count = 0;

        priority_queue<int>pq;

        for(int i = 0 ; i < size ; i++)
        {
            pq.push(happiness[i]);
        }

        int m = k;

        long long ans = 0;

        while(m--)
        {
            int a=pq.top();

            pq.pop();

            a=a-count;

            if(a<=0) break;

            count+=1;

            ans+=a;
        }

        return ans;
        
    }
};