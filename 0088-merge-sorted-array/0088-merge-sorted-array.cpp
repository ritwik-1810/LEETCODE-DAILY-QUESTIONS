class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       

      
        int i=0;

        int j=0;

        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                i++;
            }
            else
            {
                swap(nums1[i],nums2[j]);

                int k=0;

                while(k<n-1 && nums2[k]>nums2[k+1])
                {
                    swap(nums2[k],nums2[k+1]);
                    k++;
                }
            }
        }


        j=0;
        
        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[j];
            j+=1;
        }
      
    }

};