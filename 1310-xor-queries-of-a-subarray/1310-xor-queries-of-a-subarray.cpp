class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        int size = queries.size();

        vector<int>ans(size);

        int size2 = arr.size();

        vector<int>preXor(size2,arr[0]);

        for(int i=1;i<size2;i++)
        {
           preXor[i]=arr[i] ^ preXor[i-1];
        }

        for(int i=0;i<size;i++)
        {
            auto j = queries[i][0];

            auto k = queries[i][1];

            ans[i]=preXor[k] ^ (j-1 >= 0 ? preXor[j-1] : 0);
        }

        return ans;
        
    }
};