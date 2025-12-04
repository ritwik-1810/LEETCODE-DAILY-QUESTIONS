class Solution {
public:
    int countCollisions(string directions) {

        stack<char>st;

        int size = directions.size();

        int count = 0;

        for(int i=0;i<size;i++)
        {
           if(directions[i]=='R')
           {
              st.push(directions[i]);
           }
           else if(directions[i]=='S')
           {
               while(!st.empty() && st.top()=='R')
               {
                   count+=1;

                   st.pop();
               }

               st.push(directions[i]);
           }
           else
           {
               if(!st.empty())
               {
                  if(st.top()=='R')
                  {
                     count+=2;
                     st.pop();

                     while(!st.empty() && st.top()=='R')
                     {
                        count++;

                        st.pop();
                     }

                     st.push('S');
                  }
                  else count+=1;
               }
           }
        }

        return count;
    }
};