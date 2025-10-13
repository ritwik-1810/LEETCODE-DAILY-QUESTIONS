class Solution {
public:
    bool check_anagram(string s1,string s2)
    {
        if(s1.size()!=s2.size()) return false;

        unordered_map<char,int>mp;

        for(int i=0;i<s1.size();i++)
        {
            mp[s1[i]]++;
        }

        for(int i=0;i<s2.size();i++)
        {
            if(mp.find(s2[i])!=mp.end())
            {
                mp[s2[i]]--;

                if(mp[s2[i]]==0) mp.erase(s2[i]);
            }
            else
            {
                return false;
            }
                    
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {

        int size=words.size();

        for(int i=1;i<size;i++)
        {
            if(check_anagram(words[i],words[i-1]))
            { 

    
                words[i]="";

                swap(words[i],words[i-1]);
                 
            }
        }

        vector<string>ans;
        
        for(int i=0;i<size;i++)
        {
            if(words[i]!="")
              ans.push_back(words[i]);
        }

        return ans;
        
    }
};