class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        int n1 = buildings.size();

        int count=0;

        unordered_map<int , pair<int,int>>mpx;

        unordered_map<int , pair<int,int>>mpy;

        for(int i = 0 ; i < n1 ; i++)
        {
            int x = buildings[i][0];

            int y = buildings[i][1];

            if(mpx.count(x))
            {
               mpx[x].first=min(mpx[x].first,y);

               mpx[x].second=max(mpx[x].second,y);
            }
            else
            {
               mpx[x].first=y;

               mpx[x].second=y;
            }

            if(mpy.count(y))
            {
                mpy[y].first=min(mpy[y].first,x);

                mpy[y].second=max(mpy[y].second,x);
            }
            else
            {
                mpy[y].first=x;

                mpy[y].second=x;

            }
        }

        for(int i=0 ; i < n1 ; i++)
        {
            int x=buildings[i][0];

            int y=buildings[i][1];

            if(x>mpy[y].first && x<mpy[y].second  && y>mpx[x].first && y<mpx[x].second) count+=1;
        }

        return count;
    }
};