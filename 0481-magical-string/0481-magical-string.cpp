class Solution {
public:
    int magicalString(int n) {

        string s = "122";

        int n1=2;

        char last;

        while(s.size()<n)
        {
            last=s.back();

            if(s[n1]=='1')
            {
                if(last=='1')
                {
                    s.push_back('2');
                }
                else
                {
                    s.push_back('1');
                }
            }
            else
            {
                if(last=='1')
                {
                    s.push_back('2');
                    s.push_back('2');
                }
                else
                {
                    s.push_back('1');
                    s.push_back('1');
                }
            }

            n1+=1;

        }
        

        cout<<s<<endl;

        int count=0;

        for(int i=0;i<n;i++)
        {
           if(s[i]=='1') count+=1;
        }

        return count;

        
    }
};