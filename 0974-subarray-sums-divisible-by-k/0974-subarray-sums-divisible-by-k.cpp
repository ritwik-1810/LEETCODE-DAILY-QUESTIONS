class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        
        unordered_map<int,int>umap;

        int prefixSum=0;

        umap[0]=1;

        int count=0;

        for(int i=0;i<arr.size();i++)
        {
            prefixSum=(prefixSum+arr[i])%k;

            int remainder=(prefixSum+k) % k;

            // if(remainder<0)
            // {
            //     remainder+=k;
            // }

            if(umap.find(remainder)!=umap.end())
            {
               count+=umap[remainder];
            }

            umap[remainder]++;
        }

        return count;
        
    }
};