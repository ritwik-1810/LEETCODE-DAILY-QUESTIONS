class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

          int size = tasks.size();

          vector<int>freq(26,0);

          for(int i=0;i<size;i++)
          {
              freq[tasks[i]-'A']++;
          }

          priority_queue< int >pq;

          for(int i=0;i<26;i++)
          {
             if(freq[i]!=0)
             {
                 pq.push(freq[i]);
             }
          }

          int tot_pop=n+1;

          int ans=0;

          int last=0;

          while(!pq.empty())
          {
              vector<int>temp;

              int a=0;

              int size1=pq.size();

              while(a!=min(tot_pop,size1))
              {
                  temp.push_back(pq.top());

                  pq.pop();
                  
                  a++;
              }

              ans+=a+(tot_pop-a);

              for(int i=0;i<temp.size();i++)
              {
                  int val=temp[i]-1;

                  if(val>0)
                  pq.push(val);
              }

              last=a;

          }

       return ans-(tot_pop-last);
        
    }
};