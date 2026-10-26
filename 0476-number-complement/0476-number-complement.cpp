class Solution {
public:
    int findComplement(int num) {

        if(num==1) return 0;

        int bitmask = 1;

        while(bitmask<num)
        {
            bitmask<<=1;

            bitmask  =  bitmask | 1;
        } 



        return bitmask ^ num;
        
    }
};