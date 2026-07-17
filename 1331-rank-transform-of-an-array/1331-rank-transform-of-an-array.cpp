class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

       int size=arr.size();

       vector<int>sorted;

       sorted=arr;

       sort(sorted.begin(),sorted.end());

       unordered_map<int,int>mp;

       int k=1;

       for(auto it:sorted)
       {
          if(!mp.count(it))
          {
              mp[it]=k;

              k++;
          }
       }

       vector<int>ans(size);

       for(int i=0;i<arr.size();i++)
       {
           ans[i]=mp[arr[i]];
       }

       return ans;

        
    }
};