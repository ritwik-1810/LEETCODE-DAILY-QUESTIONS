class Solution {
public:
    vector<int> partitionLabels(string s) {

        int size = s.size();

        vector<int>ans;

        vector<int>alpha(26,-1);

        for(int i=size-1;i>=0;i--)
        {
            if(alpha[s[i]-'a'] == -1)
            {
               alpha[s[i]-'a'] = i;
            }
        }

        int start=0;

        int end=alpha[s[0]-'a'];

        for(int i=0;i<size;i++)
        {
            if(i>end)
            {
                ans.push_back(end-start+1);

                start=i;

                end=alpha[s[i]-'a'];

            }
            else
            {
                int a=alpha[s[i]-'a'];
                if(a>end)
                {
                    end=a;
                }

            }
        }

        ans.push_back(end-start+1);

        return ans;
        
    }
};