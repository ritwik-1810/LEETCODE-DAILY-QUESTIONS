class Solution {
public:
    int bestClosingTime(string customers) {

        int size = customers.size();

        int x=size+1;

        int mini = INT_MAX;

        vector<int>No_left(size,0);

        vector<int>Yes_right(x,0);

        if(customers[0]=='N')
        {
            No_left[0]=1;
        }

        for(int i=1;i<size;i++)
        {
            if(customers[i]=='N')
            {
                No_left[i]=No_left[i-1]+1;
            }
            else
            {
                No_left[i]=No_left[i-1];
            }
        }

        for(int i = size-1 ; i >= 0 ; i--)
        {
            if(customers[i]=='Y')
            {
                Yes_right[i]=Yes_right[i+1]+1;
            }
            else
            {
                Yes_right[i]=Yes_right[i+1];
            }
        }

        int ans=-1;

        for(int i = 0 ; i <= size ; i++)
        {

            int j=i;

            int count=0;
            
            int left= i>0 ? No_left[j-1] : 0;

            int right=Yes_right[j];

            count=left+right;
            
            if(count<mini)
            {
                ans=j;

                mini=count;
            }

        }

        return ans;
        
    }
};