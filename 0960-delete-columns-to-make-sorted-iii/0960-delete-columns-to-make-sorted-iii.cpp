class Solution {
public:
    bool check(vector<string>& strs,int i,int j)
    {
        for(int k=0;k<strs.size();k++)
        {
            if(strs[k][j]>strs[k][i]) return false;
        }

        return true;
    }
    int minDeletionSize(vector<string>& strs) {

        int rows = strs.size();

        int cols = strs[0].size();

        int count = 0;

        vector<int> vec(cols, 1);

        for(int k=0;k<cols;k++)
            {
                for(int j=0;j<k;j++)
                {
                    if(check(strs,k,j))
                    {
                        vec[k] = max(vec[j]+1,vec[k]);
                    }
                }
            }
        
        for(int i=0;i<cols;i++)
        {
            count=max(count,vec[i]);
        }


        return cols-count;
        
    }
};