class Solution {
public:
    vector<string> largestString(vector<int>& nums) {

       
vector<char> vec{'a','b','c','d','e','f','g','h',
                  'i','j','k','l','m','n','o','p',
                  'q','r','s','t','u','v','w','x',
                  'y','z'};

vector<long long> sq;
for (int i = 0; i < 26; i++) {
    sq.push_back(1LL << i);
}

vector<string> ans;

for (int i = 0; i < nums.size(); i++) {
    string a = "";
    long long n = nums[i];

    int j = 0;

    while (j < sq.size() && sq[j] <= n) {
        j++;
    }

    j--;

    int k = j;

    while (n > 0 && k >= 0) {
        if (sq[k] <= n) {
            a += vec[k];
            n -= sq[k];
        }
        if(n<sq[25])
        k--;
    }

    ans.push_back(a);
}

return ans;

    }
};