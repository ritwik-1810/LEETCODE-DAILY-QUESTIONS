class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size=s.size();

        unordered_set<int>st;

        int maxi=0;

        for(int i=0;i<size;i++)
        {
            st.clear();

            for(int j=i;j<size;j++)
            {
                if(st.find(s[j])==st.end())
                {
                    st.insert(s[j]);
                }
                else
                 break;
            }

            maxi=max(maxi,(int)st.size());
        }

        return maxi;
        
    }
};