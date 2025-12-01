class Solution {
public:
    bool check(long long mid,vector<int>& batteries,int n)
    {
         long long find=mid*n;

         long long sum=0;

         for(int i=0;i<batteries.size();i++)
         {
            sum+=min((long long)batteries[i],mid);
         }

         if(sum>=find) return true;

         return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {

        long long start=1;

        long long end=accumulate(batteries.begin(),batteries.end(),0LL)/n;

        long long ans=0;

        while(start<=end)
        {
            long long mid=start + (end-start)/2;

            if(check(mid,batteries,n))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }

        
         return ans;
    }
};