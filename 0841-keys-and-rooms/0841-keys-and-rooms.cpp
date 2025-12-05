class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n=rooms.size();

        vector<bool>visited(n,false);

        visited[0]=true;

        queue<int>qt;

        qt.push(0);

        while(!qt.empty())
        {
            int fr=qt.front();

            qt.pop();

            visited[fr]=true;

            for(auto v:rooms[fr])
            {
                if(!visited[v])
                {
                    qt.push(v);
                }
            }
        }

        for(int i = 0 ; i < visited.size() ; i++)
        {
            if(visited[i]==false) return false;
        }

        return true;
        
    }
};