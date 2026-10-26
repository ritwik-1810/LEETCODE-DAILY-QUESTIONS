class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {

        int size = encoded.size();

        vector<int>ans(size+1,first);

        for(int i=1;i<size+1;i++)
        {
            ans[i]=ans[i-1] ^ encoded[i-1];
        }


        return ans;

        
    }
};