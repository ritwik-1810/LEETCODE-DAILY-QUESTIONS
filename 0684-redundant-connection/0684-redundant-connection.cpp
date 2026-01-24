class Solution {
public:
  bool cycle_exist(
    unordered_map<int, vector<int>>& adj,
    int node,
    int parent,
    vector<bool>& vis
) {
    vis[node] = true;

    for (int v : adj[node]) {
        if (!vis[v]) {
            if (cycle_exist(adj, v, node, vis)) {
                return true;
            }
        }
        else if (v != parent) {
            return true;
        }
    }

    return false;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int size = edges.size();

        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<size;i++)
        {
           int ui=edges[i][0];

           int vi=edges[i][1];

           adj[ui].push_back(vi);

           adj[vi].push_back(ui);

           vector<bool>vis(size,false); 

           if(cycle_exist(adj,ui,-1,vis))
           {
              return {ui,vi};
           }
        }

        return {};
        
    }
};