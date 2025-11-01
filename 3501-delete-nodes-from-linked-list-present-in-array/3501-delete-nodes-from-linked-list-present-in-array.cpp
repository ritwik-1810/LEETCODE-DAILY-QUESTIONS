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
class Solution {
public:
    void remove(ListNode* head,ListNode* &prev,ListNode* &temp)
    {
        if(temp->next==NULL)
        {
            prev->next=NULL;

            temp=NULL;
        }
        else
        {
            prev->next=temp->next;

            temp=temp->next;
        }
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        int size=nums.size();

        unordered_set<int>st;

        for(int i=0;i<size;i++)
        {
            st.insert(nums[i]);
        }

        ListNode* prev=NULL;

        ListNode* temp=head;

        while(temp)
        {
            int data=temp->val;

            if(st.find(data)!=st.end())
            {
                if(prev==NULL)
                {
                    head=temp->next;

                    temp=head;
                }
                else
                {
                    remove(head,prev,temp);
                }
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }

        return head;
        
    }
};