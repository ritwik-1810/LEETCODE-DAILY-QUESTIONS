class Solution {
public:
    string removeKdigits(string nums, int k) {

         int size = nums.size();

        stack<char>st;

        for(int i=0;i<size;i++)
        {
            while(!st.empty() && st.top()>nums[i] && k>0)
            {
                st.pop();
                k--;
            }

            st.push(nums[i]);
        }

        string ans="";

        while(!st.empty())
        {
            ans+=st.top();

            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int j=0;

        while(ans[j]=='0')
        {
            j++;
        }

        string newAns= "";
        
        newAns=ans.substr(j);

        if(newAns.size()==0) return "0";

        if(k==0) return newAns;

        while(newAns.size()>0 && k>0)
        {
            newAns.pop_back();
            k--;
        } 

        return newAns==""?"0":newAns;
        
    }
};