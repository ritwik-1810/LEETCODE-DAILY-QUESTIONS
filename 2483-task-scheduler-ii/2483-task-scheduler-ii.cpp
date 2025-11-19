class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

         int size=tasks.size();

         unordered_map<int ,int>mp;

         long long now=0;

         for(int i = 0 ; i < size ; i++)
         {
              if(mp.find(tasks[i])!=mp.end())
              {

                  int idx=mp[tasks[i]];

                  int occupied=now-idx-1;

                  if(space-occupied>=0)
                  now+=space-occupied;

                  mp[tasks[i]]=now;
               
              }
              else
              {
                  mp[tasks[i]]=now;

              }
             
             now++;
             
         }

         return now;
    }
};