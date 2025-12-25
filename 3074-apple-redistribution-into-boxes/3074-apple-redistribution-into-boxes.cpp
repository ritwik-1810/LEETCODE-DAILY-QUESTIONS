class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
          
          int size = apple.size();

          int sum=0;

          for(int i=0;i<size;i++)
          {
             sum+=apple[i];
          }

          int count=0;

          sort(capacity.begin(),capacity.end());

          int size1=capacity.size();

          for(int i=size1-1;i>=0;i--)
          {
              sum-=capacity[i];

              count+=1;

              if(sum<=0) break;
          }

          return count;
        
    }
};