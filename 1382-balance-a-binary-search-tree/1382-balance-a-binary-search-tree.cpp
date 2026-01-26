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
    void inorder(vector<int>&sortArr,TreeNode* root)
    {
        if(!root) return;

        inorder(sortArr,root->left);

        sortArr.push_back(root->val);

        inorder(sortArr,root->right);

    }
    TreeNode* bb(vector<int>&sortArr,int s,int e)
    {

        if(s>e)
          return NULL;

        int mid=(s+e)/2;

        TreeNode* root = new TreeNode(sortArr[mid]);

        root->left=bb(sortArr,s,mid-1);

        root->right=bb(sortArr,mid+1,e);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int>sortArr;

        inorder(sortArr,root);

        return bb(sortArr,0,sortArr.size()-1);

    }
};