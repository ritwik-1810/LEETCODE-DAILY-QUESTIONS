class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

         for(int i=0;i<paragraph.size();i++)
         {
              if(paragraph[i]>='A' && paragraph[i]<='Z')
              {
                   paragraph[i]=tolower(paragraph[i]);
              }
              else if(!(paragraph[i]>='a' && paragraph[i]<='z') && paragraph[i]!=' ')
              {
                 paragraph[i]=' ';
              }
         }

         paragraph.push_back(' ');

         unordered_map<string,int>mp;

         string str="";

         for(int i=0;i<paragraph.size();i++)
         {
              if(paragraph[i] != ' ')
              {
                  str+=paragraph[i];
              }
              else
              {

                 while(paragraph[i] == ' ')
                 {
                    i++;
                 }

                 mp[str]++;

                 str="";

                 i--;
              }

         }

         for(int i=0;i<banned.size();i++)
         {
             if(mp.count(banned[i]))
             {
                  mp.erase(banned[i]);
             }
         }

         string ans="";

         int maxi=0;

         for(auto val:mp)
         {
             if(val.second>maxi)
             {
                 maxi=val.second;

                 ans=val.first;
             }
         }

         return ans;
    }
};