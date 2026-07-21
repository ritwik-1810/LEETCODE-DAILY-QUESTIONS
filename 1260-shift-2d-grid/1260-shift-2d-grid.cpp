class Solution {
public:
    void shifting(vector<vector<int>>& grid,int row,int col)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=col-1;j>=1;j--)
            {
                swap(grid[i][j],grid[i][j-1]);
            }
        }

        for(int i=row-1;i>=1;i--)
        {
            swap(grid[i][0],grid[i-1][0]);
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int row = grid.size();

        int col = grid[0].size();

        while(k>0)
        {
            shifting(grid,row,col);

            k--;
        }

        return grid;
    }
};