class Spreadsheet {
public:

   unordered_map<string,int>mp;
  
    Spreadsheet(int rows) {

       
    }
    
    void setCell(string cell, int value) {

        mp[cell]=value;

    }
    
    void resetCell(string cell) {

        mp[cell]=0;
    }
    
    int getValue(string formula) {

        int f=0;

        int s=0;


        string str1="";

        int i=1;

        while(formula[i]!='+')
        {
            str1.push_back(formula[i]);
  
            i++;
        }

        string str2="";

        i+=1;

        while(i<formula.size())
        {
            str2.push_back(formula[i]);

            i++;
        }


        if(str1[0]>='0' && str1[0]<='9')
        {
            f=stoi(str1);
        }
        else
        {
            if(mp.find(str1)!=mp.end())
            {
                f=mp[str1];
            }
        }

        if(str2[0]>='0' && str2[0]<='9')
        {
            s=stoi(str2);
        }
        else
        {
            if(mp.find(str2)!=mp.end())
            {
                s=mp[str2];
            }
        }


        return f+s;
          
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */