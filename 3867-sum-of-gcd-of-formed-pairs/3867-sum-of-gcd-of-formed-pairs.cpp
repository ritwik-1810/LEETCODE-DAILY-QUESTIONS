class Solution {
public:
    int gcd(int a,int b)
    {
         if(b==0)
          return a;
         
         return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {

        int size = nums.size();

        vector<int>preGcd;

        int maxi=nums[0];

        for(int i=0;i<size;i++)
        {
            maxi=max(maxi,nums[i]);

            int a=gcd(nums[i],maxi);

            preGcd.push_back(a);
        }

        sort(preGcd.begin(),preGcd.end());

        int k=0;

        int j=preGcd.size()-1;

        long long fSum=0;

        while(k<j)
        {
            int b=gcd(preGcd[k],preGcd[j]);

            fSum+=b;

            k++;

            j--;
        }

       return fSum;
        
    }
};