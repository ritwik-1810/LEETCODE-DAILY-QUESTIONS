class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int size = arr.size();

        vector<bool>vis(size,false);

        vis[start] = true;

        queue<int>q;

        q.push(start);

        while(!q.empty())
        {
            int idx = q.front();

            q.pop();

            if(arr[idx]==0) return true;

            int right = idx + arr[idx];

            int left = idx - arr[idx];

            if(right<size && right>=0 && !vis[right])
            {
                q.push(right);
                vis[right]=true;
            }

            if(left>=0 && left<size && !vis[left])
            {
                q.push(left);
                vis[left]=true;
            }
        }

        return false;
    }
};