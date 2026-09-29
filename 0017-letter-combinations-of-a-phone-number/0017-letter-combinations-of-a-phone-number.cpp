class Solution {
public:
      void solve(int idx,string &str,vector<string>&ans,vector<string>&dial,string &digits)
    {
        if(idx>=digits.size())
        {
            ans.push_back(str);
            return;
        }


        for(int i=0;i<dial[digits[idx]-'0'].size();i++)
        {
            str+=dial[digits[idx]-'0'][i];

            solve(idx+1,str,ans,dial,digits);

            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {


         vector<string>dial{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string str="";

        vector<string>ans;

        solve(0,str,ans,dial,digits);

        return ans;



        
    }
};