class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int row = grid.size();

        int col = grid[0].size();

        int i=0;

        int j=col-1;

        int count=0;

        while(i<row)
        {
            while(j>=0 && grid[i][j]<0)
            {
                j--;
            }
               
            if(j>=0) count+=(col-j-1);
            else count+=col;
            
            i+=1;
        }

        return count;
        
    }
};