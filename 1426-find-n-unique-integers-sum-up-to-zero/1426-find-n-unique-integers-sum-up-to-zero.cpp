class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int>ans;

        if(n%2!=0) ans.push_back(0);


        int fr=-1;

        int sr=1;

        while(ans.size()!=n)
        {
            ans.push_back(fr);

            ans.push_back(sr);

            fr-=1;

            sr+=1;
        }

        return ans;


        
    }
};