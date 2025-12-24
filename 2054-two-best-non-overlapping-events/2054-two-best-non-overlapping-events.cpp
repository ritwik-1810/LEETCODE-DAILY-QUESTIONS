class Solution {
public:
    static bool mycomp(vector<int>&a , vector<int>&b)
    {
        if(a[0]==b[0])
          return a[2]>b[2];

          return a[0] < b[0];
    }
    int maxTwoEvents(vector<vector<int>>& events) {

        //sort based on end time...if end time is equal then on value..

        sort(events.begin(),events.end(),mycomp);

        //now make an array to store max...

        int size=events.size();

        vector<int>maxi(size);

        int maximum=0;

        for(int i=size-1;i>=0;i--)
        {
            maxi[i]=max(maximum,events[i][2]);

            maximum=max(maximum,maxi[i]);
        }

        vector<int>firstCol;

        for(int i=0;i<size;i++)
        {
            firstCol.push_back(events[i][0]);
        }

        int singleMax=0;

        int doubleMax=0;

        for(int i=0;i<size;i++)
        {
            singleMax=max(singleMax,events[i][2]);
        }

        for(int i=0;i<size;i++)
        {
           int firstVal=events[i][2];

           int val=events[i][1];

           auto it=upper_bound(firstCol.begin(),firstCol.end(),val);

           if(it!=firstCol.end())
           {
              int idx= it - firstCol.begin();
               
              doubleMax=max(doubleMax,firstVal+maxi[idx]);

           }
        }

        return max(singleMax,doubleMax);
    }
};