class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

      int size=nums.size();

      vector<int>preSum(size,0);

      int cur=0;

      for(int i=0;i<size;i++)
      {
          preSum[i]=nums[i] + cur;

          cur=preSum[i];
      }
      
      vector<pair<int,pair<int,int>>>fr;

      vector<pair<int,pair<int,int>>>sr;

      int i=0;

      int k=firstLen-1;

      while(k<size)
      {
         int sum = i>0 ? preSum[k]-preSum[i-1] : preSum[k]-0;

         fr.push_back({sum,{i,k}});

         i+=1;

         k+=1;

      }

      i=0;

      k=secondLen-1;

      while(k<size)
      {
         int sum = i>0 ? preSum[k]-preSum[i-1] : preSum[k]-0;

         sr.push_back({sum,{i,k}});

         i+=1;

         k+=1;
      }

      int maxi=0;

      for(auto d:fr)
      {
          int s = d.first;
          int u = d.second.first;
          int v = d.second.second;

          for(auto q:sr)
          {
             int s1 = q.first;
             int u1 = q.second.first;
             int v1 = q.second.second;
             
             if(v<u1 || u>v1)
             {
                 maxi=max(maxi,s+s1);
             }

          }
      }
      
      return maxi;
    
    }
};