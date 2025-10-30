class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int size=target.size();

        int prev=0;

        int ans=0;

        for(int i=0;i<size;i++)
        {
            if(target[i]>prev)
            {
                ans+=target[i]-prev;

            }

             prev=target[i];
        }
        
        return ans;
    }
};