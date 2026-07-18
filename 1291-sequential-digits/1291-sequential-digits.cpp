class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int>pre{12,123,1234,12345,123456,1234567,12345678,123456789};

        vector<int>one{11,111,1111,11111,111111,1111111,11111111,111111111};

        int start=12;

        vector<int>ans;

        int j=0;

      while(start < low)
{
    if(start % 10 == 9)
    {
        if(j >= 7) break;
        j++;
        start = pre[j];
    }
    else
    {
        start += one[j];
    }
}
        if(start<low) return {};

        if(start>high) return {};

        ans.push_back(start);

        if(ans.size()==0) return ans;

        while(ans.back()+one[j]<=high)
        {
            
            int b=ans.back();

            if(b%10==9)
            {
               if(j>=7) break;

               j+=1;

               ans.push_back(pre[j]);

            }
            else
            {
            b+=one[j]; 

            ans.push_back(b);
            }
        }

        if(ans.back()>high) ans.pop_back();

        return ans;
        
    }
};