class Solution {
public:
    int minSubarray(vector<int>& arr, int k) {

        long long sum=0;

        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
        }

        long long rem=sum%k;

        if(rem==0) return 0;

        unordered_map<long long,int>umap;

        long long prefixSum=0;

        umap[0]=-1;

        int count=INT_MAX;

        for(int i=0;i<arr.size();i++)
        {
            prefixSum=(prefixSum+arr[i])%k;

            long long remainder=(prefixSum-rem+k)%k;


            if(umap.find(remainder)!=umap.end())
            {
               int idx=umap[remainder];

               count=min(count,i-idx);

            }

            umap[prefixSum]=i;
        }

          if(count==arr.size() || count==INT_MAX) return -1; 

          return count;
    }
};