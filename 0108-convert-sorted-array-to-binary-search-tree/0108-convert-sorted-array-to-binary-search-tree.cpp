/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int s , int e , vector<int>& nums)
    {
        if(s>e) return NULL;

        int mid = (s + e)/2;

        TreeNode* m = new TreeNode(nums[mid]);

        m->left=solve(s,mid-1,nums);

        m->right=solve(mid+1,e,nums);

        return m;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int start=0;

        int end=nums.size()-1;

        return solve(start,end,nums);

    }
};