class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int size = code.size();

        int flag=false;

        if(k<0)
        { 
            reverse(code.begin(),code.end());
            flag=true;
        }

        vector<int>vec;

        vec.insert(vec.end(),code.begin(),code.end());

        vec.insert(vec.end(),code.begin(),code.end());

        for(int i=1;i<vec.size();i++)
        {
            vec[i]+=vec[i-1];
        }

        vector<int>ans(size,0);

        if(k==0) return ans;

        int j=abs(k);

        for(int i=0;i<size;i++)
        {
            ans[i]=vec[i+j]-vec[i];
        }

        if(flag)
        {
            reverse(ans.begin(),ans.end());
        }

        return ans;

    }
};