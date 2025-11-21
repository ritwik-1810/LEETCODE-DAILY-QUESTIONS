class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int size = s.size();

        int ans = 0;

        vector<int>last(26,-1);

        for(int i = size-1 ; i >= 0 ; i--)
        {
            if(last[s[i]-'a']==-1)
            {
               last[s[i]-'a']=i;
            }
        }

        set<char>st1;


        for(int i=0;i<size;i++)
        {
            int last_idx=last[s[i]-'a'];

            set<char>st;
           
            if(st1.find(s[i])==st1.end())
            {
              for(int j=i+1 ; j < last_idx; j++)
              {
                 st.insert(s[j]);
              }
            }

            st1.insert(s[i]);

            ans+=(int)st.size();

        
        }

      return ans;
        
    }
};