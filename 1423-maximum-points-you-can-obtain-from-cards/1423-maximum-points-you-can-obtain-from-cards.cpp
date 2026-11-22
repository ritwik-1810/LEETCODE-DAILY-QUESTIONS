class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int size = cardPoints.size();

        int rightSum=0;

        for(int i=0;i<k;i++)
        {
           rightSum+=cardPoints[i];
        }

        int j=k-1;

        int maxi=rightSum;

        int leftSum=0;

        for(int i=size-1;i>=size-k;i--)
        {
            leftSum+=cardPoints[i];

            rightSum-=cardPoints[j];

            j--;

            maxi=max(maxi,leftSum+rightSum);
        }

        return maxi;
        
    }
};