class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int size  = gas.size();
        
        int balance=0;

        int expence=0;

        for(int i=0;i<size;i++)
        {
            balance+=gas[i];

            expence+=cost[i];
        }

        if(balance<expence) return -1;

        balance = 0; 

        int idx = -1;

        for(int i=0;i<size;i++)
        {
            balance += gas[i];

            if(idx==-1) idx=i;

            if(balance - cost[i] < 0 )
            {
                balance = 0;
                idx=-1;
            }
            else
            {
                balance -= cost[i];
            }
        }

        return idx;
       
    }
};