class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        int size=bits.size();

        int i=0;

        while(i<size)
        {
            if(i==size-1)
            {
                if(bits[i]==1)
                 return false;

                 return  true;
            }

            if(bits[i]==0)
             i++;
             else
             i+=2;
        }

        return false;
        
    }
};