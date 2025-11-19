class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

         int size = tasks.size();

         vector<int>freq(26,0);

         int gaddha = 0;

         for(int i = 0 ; i < size ; i++)
         {
             freq[tasks[i]-'A']++;
         }

         vector<int>freq1;

         for(int i=0;i<26;i++)
         {
             if(freq[i]!=0)
             {
                 freq1.push_back(freq[i]);
             }
         }

         sort(freq1.begin(),freq1.end());

         int val=freq1[freq1.size()-1];

         gaddha=val-1;

         int idle=(gaddha*n);

         for(int i=freq1.size()-2;i>=0;i--)
         {
             idle-=min(gaddha,freq1[i]);
         }

         if(idle>0)
           return tasks.size() + idle;

        return tasks.size();

    }
};