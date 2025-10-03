class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
/*//brute force solution->>>
        vector<int>vec;  
         
        int len=s.length();

        for(int i=0;i<len;i++)
        {
            auto temp=mp.find(s[i]);

            int t=temp->second;

            vec.push_back(t);
      
        }
        int sum=0;
        if(vec.size()==1)
          return vec[0];
        for(int i=vec.size()-1;i>0;i--)
        {
            if(vec[i]>vec[i-1])
            {
                sum+=abs(vec[i]-vec[i-1]);
                i--;
            }
            else
            {
                sum+=vec[i];
            }

        }
        if(vec[0]>=vec[1])
        {
            sum+=vec[0];
        }



        return sum;
        
     */
     //clean solution->>>

     int ans=0;

     int size_=s.size();

     for(int i=0;i<size_;i++)
     {
        if(mp[s[i]]<mp[s[i+1]])
          ans-=mp[s[i]];
        else
          ans+=mp[s[i]];
     }

       return ans;
    }
};