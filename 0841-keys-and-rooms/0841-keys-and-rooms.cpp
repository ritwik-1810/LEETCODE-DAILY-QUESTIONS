class Solution {
public:
    void dfs(vector<bool>&visited , vector<vector<int>>& rooms , int i)
    {
        visited[i]=true;

        for(auto &t:rooms[i])
        {
            if(!visited[t])
              dfs(visited,rooms,t);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n=rooms.size();

        vector<bool>visited(n,false);

        visited[0]=true;

        dfs(visited,rooms,0);

          for(int i = 0 ; i < visited.size() ; i++)
        {
            if(visited[i]==false) return false;
        }

        return true;
    }
};