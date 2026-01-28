class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       
      map<int,int>mp;

      for(int i = 0 ; i < logs.size() ; i++)
      {
          mp[logs[i][0]]+=1;

          mp[logs[i][1]]-=1;
      }

      int maxi=0;

      int val=0;

      int a=0;

      for(auto v:mp)
      {
           
           a+=v.second;
           
           if(a>maxi)
           {
              a=maxi;

              val=v.first;
           }
      }

      return val;

    }
};