class Solution {
public:
    void solve(vector<vector<int>>&ans,int start_i,int start_j,int end_i,int end_j)
    {
        for(int i=start_i;i<=end_i;i++)
        {
            for(int j=start_j;j<=end_j;j++)
            {
                ans[i][j]+=1;
            }
        }
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>ans(n,vector<int>(n,0));

        for(auto v:queries)
        {
            int start_i=v[0];

            int start_j=v[1];

            int end_i=v[2];

            int end_j=v[3];

            solve(ans,start_i,start_j,end_i,end_j);
        }

        return ans;
        
    }
};