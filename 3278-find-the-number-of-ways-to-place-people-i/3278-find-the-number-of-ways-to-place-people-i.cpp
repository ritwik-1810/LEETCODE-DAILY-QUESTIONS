class Solution {
public:
    bool isValid(int i,int j,int x1,int y1,int x2,int y2,vector<vector<int>>& points)
    {

           for(int k=0;k<points.size();k++)
           {
               int p1=points[k][0];
               int p2=points[k][1];

               if(k==i || k==j) continue;

               if(p1>=x1 && p1<=x2 && p2>=y2 && p2<=y1) return false;
           }

           return true;

    }
    int numberOfPairs(vector<vector<int>>& points) {

        int size=points.size();

        int cnt=0;

        for(int i=0;i<size;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];

            for(int j=0;j<size;j++)
            {
                if(i==j) continue;
                
                int x2=points[j][0];
                int y2=points[j][1];
                
                
                if((x1<=x2 && y1>=y2) && (isValid(i,j,x1,y1,x2,y2,points)))
                  cnt++;
            }
        }

        return cnt;
        
    }
};