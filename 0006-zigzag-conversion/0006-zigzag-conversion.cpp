class Solution {
public:
    string convert(string s, int numRows) {

        string ans="";

        int col=s.size();

        vector<vector<char>>vec(numRows,vector<char>(col,'#'));

        if(numRows==1)
          return s;

        int k=0;

        int i=0;

        int j=0;

        bool flag=true;

        while(k<s.size())
        {

           if(flag)
           {
               vec[i][j]=s[k];
               i++;
           }
           else
           {
               vec[i][j]=s[k];
               i--;
               j++;
           }

           if(i==numRows)
           {
              flag=false;

              i-=2;

              j+=1;
           }

           if(i==0)
           {
               flag=true;
           }
           
           k++;
        }

        for(int n=0;n<numRows;n++)
        {
            for(int l=0;l<s.size();l++)
            {
                if(vec[n][l]!='#')
                {
                    ans+=vec[n][l];
                }
            }
        }

        
        return ans;
        
        
    }
};