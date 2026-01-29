class MyCalendar {
public:
    map<int,int>mp;

    MyCalendar() {
        
    }
    bool check_inter(int st,int en)
    {
         int a=0;

         for(auto v:mp)
         {
            a+=v.second;

            if(a>1)
            {
                return false;
            } 
         }

         return true;
    }
    bool book(int startTime, int endTime) {

        mp[startTime]+=1;

        mp[endTime]-=1;

        if(check_inter(startTime,endTime)==false)
        {
            mp[startTime]--;
           if(mp[startTime]==0) mp.erase(startTime);

           mp[endTime]++;
           if(mp[endTime]==0) mp.erase(endTime);
            return false;
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */