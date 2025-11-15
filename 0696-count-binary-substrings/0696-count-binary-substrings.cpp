class Solution {
public:
    int countBinarySubstrings(string s) {

        vector<int>group;

        int cnt=0;

        int i=0;

        while(i<s.size())
        {

            if(s[i]=='0')
            {
                while(s[i]=='0')
                {
                    cnt+=1;

                    i++;
                }

                group.push_back(cnt);
            }
            else
            {
                while(s[i]=='1')
                {
                    cnt+=1;

                    i++;
                }

                group.push_back(cnt);
            }

            cnt=0;
        }

        int res=0;

        for(int i=0;i<group.size()-1;i++)
        {
            res+=min(group[i],group[i+1]);
        }

        return res;
        
    }
};