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
    void solve(TreeNode* root,int &k,int &smallestNumber)
    {
        if(!root) return;

        solve(root->left,k,smallestNumber);

        k--;

        if(k==0)
          smallestNumber=root->val;

        solve(root->right,k,smallestNumber);

    }
    int kthSmallest(TreeNode* root, int k) {

        int smallestNumber=-1;

        solve(root,k,smallestNumber);

        return smallestNumber;
        
    }
};