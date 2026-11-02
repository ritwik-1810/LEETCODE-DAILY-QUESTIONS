class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        
        int size = arr.size();

        int sum = 0;

        for(int i=0;i<size;i++)
        {
            sum+=arr[i];
        }
    
         int target = sum / 3;

         if((sum%3)!=0) return false;

        int curr = 0;
        int parts = 0;

        for (int i = 0; i < arr.size() - 1; i++) {

            curr += arr[i];

            if (curr == target) {
                parts++;
                curr = 0;
            }

            if (parts == 2) return true;
        }

        return false;

    }
};