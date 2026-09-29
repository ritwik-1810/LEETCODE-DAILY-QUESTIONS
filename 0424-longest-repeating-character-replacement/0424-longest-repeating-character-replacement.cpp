class Solution {
public:
    int characterReplacement(string s, int k) {

         int size = s.size();

        int i=0,j=0;

        unordered_map<char,int>mp;

        int maximum = 0 ;

        while(j<size)
        {
            mp[s[j]]++;
            
            int maxEle=0;

            int winSize=j-i+1;

            for(auto val:mp)
            {
                maxEle=max(maxEle,val.second);
            }

            if((winSize-maxEle)<=k)
            {
                maximum=max(maximum,winSize);
            }
            else
            {
                mp[s[i]]--;

                i++;
            }

            j++;

        } 

        return maximum;

    }
};