class Solution {
public:
    string removeDuplicateLetters(string s) {

         int size=s.size();
        
        string ans="";

        vector<bool>isTrue(26);

        vector<int>last(26,-1);

        for(int i=size-1;i>=0;i--)
        {
            if(last[s[i]-'a']==-1)
            last[s[i]-'a'] = i;
        }

        for(int i=0;i<size;i++)
        {
            if(isTrue[s[i]-'a']==true)
             continue;

                while(ans.size()>0 && ans.back()>s[i])
                {
                    if(last[ans.back()-'a']<=i)
                     break;
                    
                    isTrue[ans.back()-'a'] = false;
                    ans.pop_back();
                }
            
             ans+=s[i];

             isTrue[s[i]-'a'] = true;

             cout<<ans<<endl;
            
        }

        return ans;
        
    }
};