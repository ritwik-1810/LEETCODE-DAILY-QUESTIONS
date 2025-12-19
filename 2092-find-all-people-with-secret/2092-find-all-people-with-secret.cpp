class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int fP) {

          map<int , vector<pair<int,int>>>timeMap;

          for(auto meet:meetings)
          {
              int first=meet[0];

              int second=meet[1];

              int time=meet[2];

              timeMap[time].push_back({first,second});
          }

          vector<bool>ans(n,false);

          ans[0]=true;

          ans[fP]=true;

          for(auto v:timeMap)
          {
                unordered_map<int,vector<int>>dummy;

                unordered_set<int>st;

                for(auto s:v.second)
                {
                    int fr=s.first;

                    int sec=s.second;

                    dummy[fr].push_back(sec);

                    dummy[sec].push_back(fr);

                    st.insert(fr);

                    st.insert(sec);
                }

                queue<int>qt;

                for(auto s:st)
                {
                    if(ans[s]) qt.push(s);
                }

                int size=st.size();

                unordered_set<int>vis;

                while(!qt.empty())
                {
                    int a=qt.front();

                    qt.pop();

                    if(vis.count(a)) continue;

                    vis.insert(a);

                    ans[a]=true;

                    for(auto d:dummy[a])
                    {
                        if(!vis.count(d)) qt.push(d);
                    }
                }


          }

          vector<int>an;

          for(int i=0;i<n;i++)
          {
             if(ans[i]) an.push_back(i);
          }

          return an;
        
    }
};