class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int size = asteroids.size();

        stack<int>st;

        vector<int>ans;

        for(int i = 0 ; i < size ; i++)
        {
           if(asteroids[i]>0)
           {
              st.push(asteroids[i]);
           }
           else
           {
               if(st.empty() || st.top()<0)
               {
                  st.push(asteroids[i]);
               }
               else
               {
                  bool flag = false;

                  while(!st.empty() && st.top()<=abs(asteroids[i]) && st.top()>0)
                  {
                       if(st.top()==abs(asteroids[i]))
                       {
                          flag=true;

                          st.pop();

                          break;
                       }
                       else
                       {
                          st.pop();
                       }
                  }

                  if(flag==false && (st.empty() || st.top()<0))
                    st.push(asteroids[i]);

               }
           }

        }

         while(!st.empty())
         {
            ans.push_back(st.top());

            st.pop();
         }

         reverse(ans.begin(),ans.end());

         return ans;


        
    }
};