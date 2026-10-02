class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
          
           int size = hand.size();
        
        map<int,int>freq;

        for(int i=0;i<size;i++)
        {
            freq[hand[i]]++;
        }

        sort(hand.begin(),hand.end());

        for(int i=0;i<hand.size();i++)
        {
            int grp=0;

            int key1=hand[i];

             if(!freq.count(key1)) continue;

            while(grp<groupSize)
            {
                if(!freq.count(key1)) return false;

                freq[key1]--;

                grp+=1;

                if(freq[key1]==0)
                {
                    freq.erase(key1);
                }

                key1+=1;
            }

        }

       return true;
        
        
    }
};