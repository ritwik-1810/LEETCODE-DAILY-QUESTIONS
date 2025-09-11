class Solution {
public:
    string sortVowels(string s) {

        int size=s.size();

        string str="";

        for(int i=0;i<size;i++)
        {
             char a=tolower(s[i]);
             
             if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
             {
                 str+=s[i];
             }
        }

        sort(str.begin(),str.end());

        int j=0;

        for(int i=0;i<size;i++)
        {
            char a=tolower(s[i]);
             
             if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
             {
                 s[i]=str[j];

                 j++;
             }
        }

        return s;
        
    }
};