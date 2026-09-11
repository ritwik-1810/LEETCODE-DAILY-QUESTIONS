/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<int,TreeNode*>mp;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            auto v=q.front();

            auto left=v->left;

            auto right=v->right;

            q.pop();

            if(left)
            {
               mp[left->val]=v;
               q.push(left);
            }

            if(right)
            {
              mp[right->val]=v;
              q.push(right);
            }
        }

        unordered_map<TreeNode*,bool>vis;

        vector<int>ans;

        queue<pair<TreeNode*,int>>q1;


        q1.push({target,0});

        while(!q1.empty())
        {
            auto [node,d]=q1.front();

            q1.pop();

            vis[node]=true;

            if(d==k)
            {
                ans.push_back(node->val);
            }

            auto left=node->left;

            auto right=node->right;

            auto t= mp.count(node->val) ? mp[node->val] : NULL;

            if(!vis.count(left) && left!=NULL)
            {
                q1.push({left,d+1});
            }
            
            if(!vis.count(right) && right!=NULL)
            {
                q1.push({right,d+1});
            }

            if(!vis.count(t) && t!=NULL)
            {
                q1.push({t,d+1});
            }



        }
 
      return ans;
        
    }
};