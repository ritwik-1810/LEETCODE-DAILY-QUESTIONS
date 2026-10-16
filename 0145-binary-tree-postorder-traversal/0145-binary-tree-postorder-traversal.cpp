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
    TreeNode* findPrede(TreeNode* root)
    {
        TreeNode* curr=root->right;

        while(curr->left && curr->left!=root)
        {
            curr=curr->left;
        }

        return curr;
    }
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;

        TreeNode* curr = root;

        while(curr!=nullptr)
        {
            if(curr->right == nullptr)
            {
                ans.push_back(curr->val);

                curr=curr->left;
            }
            else
            {
                
                TreeNode* prede=findPrede(curr);

                if(prede->left==nullptr)
                {
                    prede->left=curr;

                    ans.push_back(curr->val);

                    curr=curr->right;
                }
                else
                {
                    prede->left=nullptr;

                    curr=curr->left;
                }
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};