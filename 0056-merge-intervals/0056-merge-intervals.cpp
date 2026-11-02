class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int size = intervals.size();

        auto lambda = [](vector<int>&a,vector<int>&b)
        {
            return a[0] < b[0];
        };

        sort(intervals.begin(),intervals.end(),lambda);

        vector<vector<int>>ans;
         
        ans.push_back(intervals[0]);
      
        for(int i=1;i<size;i++)
        {
            int s=ans.size()-1;

            if(intervals[i][0]<=ans[s][1])
            {
                ans[s][1]=max(intervals[i][1],ans[s][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
        
    }
};