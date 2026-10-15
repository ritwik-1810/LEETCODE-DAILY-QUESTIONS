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
class BSTIterator {
public:
    stack<TreeNode*>inorder;
    TreeNode* curr;
    bool size;
    BSTIterator(TreeNode* root) {

        curr=root;
        size=true;
        
    }
    
    int next() {

        while(true)
        {
           if(curr)
           {
              inorder.push(curr);

              curr=curr->left;
           }
           else
           {
              
              TreeNode* temp=inorder.top();

              inorder.pop();

              if(temp->right) curr=temp->right;

              if(inorder.size()==0 && !curr)
                size=false;

              return temp->val;
           }

        }
        
    }
    
    bool hasNext() {

        return size;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */