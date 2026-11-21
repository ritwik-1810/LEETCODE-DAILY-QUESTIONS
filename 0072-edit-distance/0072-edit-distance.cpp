class Solution {
public:
    int solve(string &w1,string &w2,int i,int j,vector<vector<int>>&t)
    {
        //base case

        if(i>=w1.size())
        {
            return w2.size()-j;
        }
        if(j>=w2.size())
        {
            return w1.size()-i;
        }

        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        
        int ans=0;
  

        if(w1[i]==w2[j])
        {
          
           return solve(w1,w2,i+1,j+1,t);
        }
        else
        {
           // insert
           int s2=1+solve(w1,w2,i,j+1,t);
           //delete
           int s3=1+solve(w1,w2,i+1,j,t);
           //replace
           int s4=1+solve(w1,w2,i+1,j+1,t);
           
           ans=min(s2,min(s3,s4));        
           
        }
       
        return t[i][j]=ans;
    }
    int minDistance(string word1, string word2) {

        int ans;

        int n=word1.size();

        int m=word2.size();

        vector<vector<int>>t(n+1,vector<int>(m+1,-1));

        int i=0;
        int j=0;

        ans=solve(word1,word2,i,j,t);

        return ans;

    }
};