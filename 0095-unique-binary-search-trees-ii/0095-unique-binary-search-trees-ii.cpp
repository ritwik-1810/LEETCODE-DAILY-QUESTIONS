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
    vector<TreeNode*>solve(int l,int r)
    {
        if(l>r) return {nullptr};

        if(l==r) return {new TreeNode(l)};

        vector<TreeNode*>result;

        for(int i=l;i<=r;i++)
        {
             vector<TreeNode*>leftRoot=solve(l,i-1);

             vector<TreeNode*>rightRoot=solve(i+1,r);

             for(int j=0;j<leftRoot.size();j++)
             {
                for(int k=0;k<rightRoot.size();k++)
                {
                    TreeNode* root=new TreeNode(i);

                    root->left=leftRoot[j];

                    root->right=rightRoot[k];

                    result.push_back(root);
                }
             }
        }

        return result;
        
    }
    vector<TreeNode*> generateTrees(int n) {

          return solve(1,n);
        
    }
};