class Solution {
public:
    bool isSorted(vector<int>&arr)
    {
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i+1]) return false;
        }

        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {

        vector<int>arr=nums;

        int cnt=0;

        while(true)
        {
            if(isSorted(arr)) return cnt;

            vector<int>n;

            cnt+=1;

            int mini=INT_MAX;

            int idx=-1;

            for(int i=0;i<arr.size()-1;i++)
            {
                if((arr[i]+arr[i+1])<mini)
                {
                    idx=i;

                    mini=arr[i]+arr[i+1];
                }
            }

            arr[idx]=mini;

            arr[idx+1]=INT_MIN;

            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]!=INT_MIN)
                n.push_back(arr[i]);
            }

            arr=n;
        }

        return cnt;
        
    }
};