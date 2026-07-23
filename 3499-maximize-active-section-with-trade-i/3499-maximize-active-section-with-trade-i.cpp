class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int size = s.size();

        int totalOne=0;

        for(int i=0;i<size;i++)
        {
           if(s[i]=='1')
            totalOne+=1;
        }

        vector<int>leftZero(size,0);

        vector<int>rightZero(size,0);

        if(s[size-1]=='0')
        {
            leftZero[size-1]=1;
        }

        if(s[0]=='0')
        {
            rightZero[0]=1;
        }

        for(int i=size-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                leftZero[i]=1+leftZero[i+1];
            }
            else
            {
                leftZero[i]=0;
            }
        }
        
        for(int i=1;i<size;i++)
        {
            if(s[i]=='0')
            {
                rightZero[i]=1+rightZero[i-1];
            }
            else
            {
                rightZero[i]=0;
            }
        }

        int maxZero=0;

        int j=0;

        int k=0;

        while(k<size)
        {
            if(s[k]=='0')
             {
                j++;
                k++;
             }
             else
             {
                 while(k<size && s[k]=='1')
                 {
                    k++;
                 }

                 int left = k < size ? leftZero[k] : 0 ;

                 int right = j-1 >= 0 ? rightZero[j-1] : 0 ;

                 if(left!=0 && right!=0)
                 maxZero=max(maxZero,left+right);

                 j=k;

             }
        }

        return totalOne + maxZero;

        
    }
};