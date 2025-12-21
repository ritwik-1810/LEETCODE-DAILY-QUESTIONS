class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int row = strs.size();

        int col = strs[0].size();

        vector<bool>prev(row,false);

        prev[row-1] = true;

        int count = 0;

        for(int i = 0 ; i < col ; i++)
        {
            bool s=false;

            for(int j = 0 ; j < row-1 ; j++)
            {
                if(strs[j][i]>strs[j+1][i] && !prev[j])
                {
                    s=true;
                    count+=1;
                    break;
                }
        
            } 

            if(s) continue;

            for(int k=0;k<row-1;k++)
            {
                prev[k]=prev[k] | strs[k][i] < strs[k+1][i];
            }

        }

        return count;
    }
};