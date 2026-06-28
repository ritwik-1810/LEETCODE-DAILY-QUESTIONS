class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        int size = arr.size();

        sort(arr.begin(),arr.end());

        
                if(arr[0]!=1)
                {
                    arr[0]=1;
                }

        for(int i=1;i<size;i++)
        {
            if(abs(arr[i]-arr[i-1])>1)
            {
                arr[i]=arr[i-1]+1;
            }
        }

        int maxi=1;

        for(int i=0;i<size;i++)
        {
            maxi=max(maxi,arr[i]);
        }

        return maxi;
    }
};