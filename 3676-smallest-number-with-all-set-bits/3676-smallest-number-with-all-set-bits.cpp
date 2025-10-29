class Solution {
public:
    int smallestNumber(int n) {

        

        int val=1;

        while(val<n)
        {
            val=(2*val)+1;
        }

        return val;

        
    }
};