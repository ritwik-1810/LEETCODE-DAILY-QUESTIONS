class Solution {
public:
    string smallestPalindrome(string s) {

        int size = s.size();

        map<char,int>mp;

        bool odd=false;

        for(int i=0;i<size;i++)
        {
            mp[s[i]]++;
        }

        char ch = '.';

        int no=0;

        string str = "";

        for(auto st:mp)
        {
            if(st.second%2!=0)
            {
              odd=true;
              ch=st.first;
              no=st.second;
            }
            
               string q(st.second/2,st.first);
               str  = str + q;
            
        }

        string rev = str;

       

        reverse(rev.begin(),rev.end());

        if(ch!='.' ) return str + string(1,ch) + rev;
       

        return str+rev;

    }
};