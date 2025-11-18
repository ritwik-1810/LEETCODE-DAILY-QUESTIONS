class Solution {
public:
    vector<int> grayCode(int n) {

        if(n==1) return {0,1};

        int val=pow(2,n);

        vector<int>ans(val);
        
        ans[0]=0;

         ans[1]=1;

          ans[2]=3;

           ans[3]=2;

        int n1=4;
        
        int idx=1;

        int size=4;
       
        while(n1<val)
        {
            ans[n1]=ans[n1-(idx)] + size;

            idx+=2;

            n1++;

            if(n1%size==0)
            {
                size=size*2;
                idx=1;
            }

        }

        return ans;
        
    }
};