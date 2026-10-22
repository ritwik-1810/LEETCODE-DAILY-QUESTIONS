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
    vector<TreeNode*> solve(int start,int end)
    {
          if(start>end) return {nullptr};

          if(start==end)
          {
              return {new TreeNode(start)};
          }

          
          vector<TreeNode*>result;

          for(int i=start;i<=end;i++)
          {
              
            vector<TreeNode*>leftBST=solve(start,i-1);

            vector<TreeNode*>rightBST=solve(i+1,end);

            for(int j=0;j<leftBST.size();j++)
            {
                for(int k=0;k<rightBST.size();k++)
                {
                    TreeNode* root=new TreeNode(i);

                    root->left=leftBST[j];

                    root->right=rightBST[k];

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