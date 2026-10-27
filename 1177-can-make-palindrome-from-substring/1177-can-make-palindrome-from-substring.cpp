class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        unordered_map<int,vector<int>>mp;

        int size = s.size();

        vector<int>freq(26,0);

        mp[-1]=freq;

        for(int i=0;i<size;i++)
        {
            freq[s[i]-'a']++;

            mp[i] = freq;
        }

        int sizeQuery=queries.size();

        vector<bool>ans(sizeQuery,false);

        for(int i=0;i<sizeQuery;i++)
        {
            int l=queries[i][0];

            int r=queries[i][1];

            int k=queries[i][2];

            int count=0;
            
            for(int i=0;i<26;i++)
            {
                int odd = mp[r][i] - mp[l-1][i];

                if(odd%2!=0) count+=1;
            }

            int canChange=count/2;

            if(k>=canChange) ans[i]=true;

        }

        return ans;
        
    }
};