class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size=s.size();

        unordered_map<int,int>st;

        int maxi=0;

        int i=0;

        int j=0;

        while(j<size)
        {
             st[s[j]]++;

            while(i<j && st[s[j]]>1)
            {
                st[s[i]]--;

                if(st[s[i]]==0)
                  st.erase(s[i]);

                i++;
            }
            
            maxi=max(maxi,(int)st.size());

            j++;
        }

        return maxi;
        
    }
};