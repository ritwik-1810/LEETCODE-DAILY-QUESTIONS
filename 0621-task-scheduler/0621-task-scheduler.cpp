class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int size = tasks.size();

        vector<int>freq(26,0);

        for(int i=0;i<size;i++)
        {
            freq[tasks[i]-'A']++;
        }

        sort(freq.begin(),freq.end());

        vector<int>vec;

        for(int i=25;i>=0;i--)
        {
            if(freq[i]!=0)
              vec.push_back(freq[i]);
        }

        int fr=vec[0];

        int gaddha=fr-1;

        int place=gaddha*n;

        for(int i=1;i<vec.size();i++)
        {
            int val=min(gaddha,vec[i]);

            place-=val;
        }

        if(place>0) return tasks.size()+place;

        return tasks.size();
        
    }
};