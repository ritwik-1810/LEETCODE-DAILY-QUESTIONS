class Solution {
public:
    static bool mycomp(const vector<string>&a ,const vector<string>&b)
    {
       int t1 = stoi(a[1]);
    int t2 = stoi(b[1]);

    if (t1 != t2)
        return t1 < t2;

    // same time → OFFLINE first
    return a[0] == "OFFLINE" && b[0] == "MESSAGE";
    }
    void changeMention(vector<string>& eve,set<int>&st, vector<int>&mentions)
    {

        if(eve[2]=="ALL")
        {
            for(int i=0;i<mentions.size();i++)
            {
               mentions[i]++;
            }
        }
        else if(eve[2]=="HERE")
        {
            for(auto s:st)
            {
                mentions[s]+=1;
            }
        }
        else
        {
            stringstream ss(eve[2]);

        string token;

        vector<string>ids;

        while(ss >> token)
        {
           ids.push_back(token);
        }
            for(int i=0;i<ids.size();i++)
            {
                mentions[stoi(ids[i].substr(2))]++;
            }
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        int size = events.size();

        vector<int>mentions(numberOfUsers,0);

        //queue for storing the offline

        queue<pair<int,int>>qt;

        //set for storing the online..

        set<int>st;

        //initially all are active so push all in active..

        for(int i=0;i<numberOfUsers;i++)
        {
            st.insert(i);
        }

        //sort the events vector based on events timestamps, if timestamp is same the offline first..

        sort(begin(events),end(events),mycomp);

        //traverse the events...

        for(int i = 0 ; i < size ; i++)
        {
            int tt=stoi(events[i][1]);

                 while(!qt.empty() && qt.front().second <= tt)
                 {
                     auto [id,t]=qt.front();

                     qt.pop();

                     st.insert(id);
                 }
            if(events[i][0]=="MESSAGE")
            {

                 changeMention(events[i],st,mentions);
            }
            else
            {
                 int id=stoi(events[i][2]);
                 int tt=stoi(events[i][1]);

                 st.erase(id);

                 qt.push({id,tt+60});
            }
        }


        return mentions;
        
    }
};