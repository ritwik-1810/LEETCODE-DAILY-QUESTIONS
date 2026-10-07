/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode* constructUniqueTree(vector<int>& preorder, vector<int>& inorder,int l,int &i,int e)
    {
        
        if(l>e)
        {
            return nullptr;
        }

        int rootnode=preorder[i++];

        int j=l;

        while(j<=e && inorder[j]!=rootnode)
        {
            j++;
        }

        if(j>e) return nullptr;

        TreeNode* root=new TreeNode(inorder[j]);

        root->left=constructUniqueTree(preorder,inorder,l,i,j-1);

        root->right=constructUniqueTree(preorder,inorder,j+1,i,e);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //your code goes here
        

        int size = preorder.size();

        int idx=0;

        return constructUniqueTree(preorder,inorder,0,idx,size-1);
        
    }
};