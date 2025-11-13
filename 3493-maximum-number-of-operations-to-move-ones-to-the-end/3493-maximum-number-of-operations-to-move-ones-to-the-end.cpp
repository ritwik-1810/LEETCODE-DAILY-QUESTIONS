class Solution {
public:
    int maxOperations(string s) {

        int size=s.size();

        int prev=0;

        int cnt=0;

        int ans=0;

        for(int i=0;i<size-1;i++)
        {
            if(s[i]=='1')
            {
                cnt+=1;
            }

            if(s[i]=='1' && s[i+1]=='0')
            {
                prev=prev+cnt;

                cnt=0;

                ans+=prev;
            }

        }

        return ans;

        
    }
};