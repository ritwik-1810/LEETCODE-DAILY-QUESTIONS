class Solution {
public:
    int findClosest(int x, int y, int z) {

        int x_dis=abs(x-z);

        int y_dis=abs(y-z);

        if(x_dis==y_dis) return 0;

        if(x_dis>y_dis) return 2;

        return 1;
        
        
    }
};