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
    vector<TreeNode*> solve(int start,int end,map<pair<int,int>,vector<TreeNode*>>&dp)
    {
          if(start>end) return {nullptr};

          if(start==end)
          {
              return {new TreeNode(0)};
          }
          
          if(dp.count({start,end}))
          {
              return dp[{start,end}];
          }
          
          vector<TreeNode*>result;

          for(int i=start;i<=end;i++)
          {
              
            vector<TreeNode*>leftBST=solve(start,i-1,dp);

            vector<TreeNode*>rightBST=solve(i+1,end,dp);

            for(int j=0;j<leftBST.size();j++)
            {
                for(int k=0;k<rightBST.size();k++)
                {
                    TreeNode* root=new TreeNode(0);
                    
                    if(!leftBST[j] && !rightBST[k])
                    {
                       root->left=leftBST[j];

                       root->right=rightBST[k];
                    }
                    else if(leftBST[j] && rightBST[k])
                    {
                       root->left=leftBST[j];

                       root->right=rightBST[k];
                    }
                    else
                    {
                        continue;
                    }

                    result.push_back(root);
                }

            }
             
          }

          return dp[{start,end}]=result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {

        map<pair<int,int>,vector<TreeNode*>>dp;

        return  solve(1,n,dp);
        
    }
};