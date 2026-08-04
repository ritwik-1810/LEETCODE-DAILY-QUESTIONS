class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_map<string,int>mp;

        for(auto it:deadends)
        {
            mp[it]++;
        }

        int mini=INT_MAX;

        queue<pair<string,int>>q;

        q.push({"0000",0});

        unordered_map<string,bool>vis;

        unordered_map<char,pair<char,char>>l{{'0',{'9','1'}},{'9',{'8','0'}},{'1',{'0','2'}},{'2',{'1','3'}},{'3',{'2','4'}},{'4',{'3','5'}},{'5',{'4','6'}},{'6',{'5','7'}},{'7',{'6','8'}},{'8',{'7','9'}}};

        vis["0000"]=true;

        while(!q.empty())
        {
            auto [str,cnt] = q.front();

            q.pop();

            if(mp.find(str)!=mp.end())
            {
               continue;
            }

            if(str==target)
            {
                mini=min(mini,cnt);
            }

            for(int i=0;i<4;i++)
            {
                string s1=str;
                string s2=str;

                char ch=str[i];

                char ch1=l[ch].first;

                char ch2=l[ch].second;

                s1[i]=ch1;
                s2[i]=ch2;

                if(!vis.count(s1))
                {
                   vis[s1]=true;

                   q.push({s1,cnt+1});
                }

                if(!vis.count(s2))
                {
                    vis[s2]=true;

                    q.push({s2,cnt+1});
                }


            }
        }

        if(mini==INT_MAX) return -1;

        return mini;
        
    }
};