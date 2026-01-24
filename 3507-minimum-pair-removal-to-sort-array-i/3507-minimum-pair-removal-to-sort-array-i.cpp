class Solution {
public:
    bool isSorted(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i + 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr = nums;
        int cnt = 0;

        while (!isSorted(arr)) {
            int idx = -1;
            int mini = INT_MAX;

            // find minimum adjacent pair
            for (int i = 0; i < arr.size() - 1; i++) {
                if (arr[i] + arr[i + 1] < mini) {
                    mini = arr[i] + arr[i + 1];
                    idx = i;
                }
            }

            // merge pair
            arr[idx] = mini;
            arr.erase(arr.begin() + idx + 1);
            cnt++;
        }

        return cnt;
    }
};
