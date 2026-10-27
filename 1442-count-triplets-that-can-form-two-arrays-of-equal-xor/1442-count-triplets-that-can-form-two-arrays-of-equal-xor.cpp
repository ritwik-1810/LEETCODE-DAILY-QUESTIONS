class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int size = arr.size();

        vector<int>preXor(size,arr[0]);

        for(int i = 1 ; i < size ; i++)
        {
            preXor[i] = arr[i] ^ preXor[i-1];
        }

        int cnt=0;

        for(int i=0;i<size;i++)
        {
            for(int k=i+1;k<size;k++)
            {

               int a = preXor[k] ^ (i-1>=0 ? preXor[i-1] : 0);

               if(a==0) cnt+=k-i;

            }
        }

        return cnt;

    }
};