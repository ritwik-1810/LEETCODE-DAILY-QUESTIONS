class Solution {
public:
    string longestPrefix(string s) {

        int size = s.size();

        vector<int>LPS(size);

        if(size==0) return "";

        int pref=0;

        int suff=1;

        while(suff<size)
        {
            if(s[pref]==s[suff])
            {
                LPS[suff]=pref+1;

                pref++;

                suff++;
            }
            else
            {
                if(pref==0)
                {
                   LPS[suff]=0;

                   suff++;
                }
                else
                {
                    pref=LPS[pref-1];
                }
            }
        }

        return s.substr(0,LPS[size-1]);
        
    }
};