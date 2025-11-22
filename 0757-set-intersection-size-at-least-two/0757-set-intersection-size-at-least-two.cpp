class Solution {
public:
    static bool mycomp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1]) return a[0] > b[0];

        return a[1] < b[1]; 
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        int size=intervals.size();

        sort(intervals.begin(),intervals.end(),mycomp);

        int first=-1;

        int second=-1;

        int ans=0;

        for(int i = 0 ; i < size ; i++)
        {
             int s=intervals[i][0];

             int e=intervals[i][1];

             if(first >= s && second <=e) 
             {
                cout<<4<<endl;
                continue;
             }


             if(second < s)
             {
                ans+=2;

                second=e;

                first=e-1;

                cout<<2<<endl;
             }
             else
             {
                 ans+=1;

                 first=second;

                 second=e;

                 cout<<1<<endl;
             }

        }

        return ans;
        
    }
};