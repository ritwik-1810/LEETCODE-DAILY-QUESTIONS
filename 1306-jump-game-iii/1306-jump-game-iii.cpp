class Solution {
public:
    bool solve(vector<int>& arr,int s,vector<bool>&vis)
    {

        if(arr[s]==0) return true;

        vis[s]=true;

        bool left=false;bool right=false;
         
        if(s-arr[s]>=0 && vis[s-arr[s]]==false)
        left=solve(arr,s-arr[s],vis);
 
        if(s+arr[s]<arr.size() && vis[s+arr[s]]==false)
        right=solve(arr,s+arr[s],vis);

        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {

        vector<bool>vis(arr.size(),false);

         return solve(arr,start,vis);
        
    }
};