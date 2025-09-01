class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         
         int size=classes.size();

         priority_queue<tuple<double,int,int>>pq;

         for(int i=0;i<size;i++)
         {
             double avg=(double)(classes[i][0]+1)/(double)(classes[i][1]+1)-((double)classes[i][0]/(double)classes[i][1]);

             pq.push({avg,classes[i][0],classes[i][1]});
         }

         while(extraStudents--)
         {
              auto [avg,num,den]=pq.top();

               num=num+1;

               den=den+1; 

              pq.pop();

              double av=((double)(num+1)/(double)(den+1))-((double)(num)/(double)(den));

              pq.push({av,num,den});
        
         }

         double sum=0;

         while(!pq.empty())
         {
              auto [avg,num,den]=pq.top();

              pq.pop();

              sum=sum+((double)num/den);
         }

         return sum/size;

    }
};