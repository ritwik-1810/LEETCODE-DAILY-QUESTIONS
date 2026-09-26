class Solution {
public:
    char repeatedCharacter(string s) {

        int size = s.size();

        set<char>st;

        for(int i=0;i<size-1;i++)
        {
            st.clear();

            for(int j=i+1;j<size;j++)
            {
                if(s[i]==s[j])
                {
                     if((j-i-1)==st.size())
                     {
                        return s[i];
                     }
                     else
                      break;
                }
                else
                {
                    st.insert(s[j]);
                }
            }
        }
        
        return ' ';
    }
};