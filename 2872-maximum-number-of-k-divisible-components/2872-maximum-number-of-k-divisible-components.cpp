class Solution {
public:
    long long dfs(int i, unordered_map<int,vector<int>>& adj,
                  vector<bool>& vis, vector<int>& values, 
                  int k, int& cnt)
    {
        vis[i] = true;

        long long sum = values[i];

        for (int t : adj[i]) {

            if (!vis[t]) {
                long long child = dfs(t, adj, vis, values, k, cnt);
                sum += child;
            }
        }

        // if this subtree forms a valid component
        if (sum % k == 0) {
            cnt++;
            return 0;   // cut here
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k)
    {
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        
        int cnt = 0;

        dfs(0, adj, vis, values, k, cnt);

        return cnt;
    }
};
