class Solution {
public:
    int countVowelSubstrings(string word) {

         int size=word.size();

        int it=word.size()-1;

        int idx=word.size();

        vector<int>prepro(word.size());

        while(it>=0)
        {

            prepro[it]=idx;

             if(word[it]!='a' && word[it]!='e' && word[it]!='i' && word[it]!='o' && word[it]!='u')
             {
                 idx=it;
             }

            it--;
        }

        long long i=0;
        long long j=0;
        long long count=0;

        long long ans=0;

        unordered_map<char,int>mp;

        while(j<word.size())
        {
             if(word[j]!='a' && word[j]!='e' && word[j]!='i' && word[j]!='o' && word[j]!='u')
             {
                 count++;
             }
             else if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u')
             {
                 mp[word[j]]++;
             }


             while(mp.size()==5 && count>=0)
             {
                  if(count==0)
                  {
                     int a=prepro[j];

                     ans=ans+(a-j);
                  }  

                  if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
                  {
                     mp[word[i]]--;

                     if(mp[word[i]]==0)
                     {
                        mp.erase(word[i]);
                     }

                  }

                  if(word[i]!='a' && word[i]!='e' && word[i]!='i' && word[i]!='o' && word[i]!='u')
                  {
                     count--;
                  }

                 
                i++;
             }
             
             j++;

        }

        return ans;
        
    }
};