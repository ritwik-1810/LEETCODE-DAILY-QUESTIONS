/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* constructTree(vector<int>&inorder,int s,int e)
    {
        if(s>e) return nullptr;

        int mid=(s+e)/2;

        TreeNode* root=new TreeNode(inorder[mid]);

        root->left=constructTree(inorder,s,mid-1);

        root->right=constructTree(inorder,mid+1,e);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int>inorder;

        while(head)
        {
            inorder.push_back(head->val);

            head=head->next;
        }

        return constructTree(inorder,0,inorder.size()-1);
        
    }
};