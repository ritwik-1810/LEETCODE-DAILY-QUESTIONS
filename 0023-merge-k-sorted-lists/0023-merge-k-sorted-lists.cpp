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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(int i=0;i<lists.size();i++)
        {
            ListNode* first=lists[i];
            
            if(first!=NULL)
            {
            int val=first->val;

            pq.push({val,first});

            cout<<first->val<<endl;
            }

        }

        ListNode* head1=NULL;

        ListNode* curr=NULL;

        while(!pq.empty())
        {
            ListNode* node=pq.top().second;

            pq.pop();

            ListNode* nxtNode=node->next;
            
            if(nxtNode!=NULL)
            {
             int val = nxtNode->val;
             pq.push({val,nxtNode});
            }


            if(head1==NULL)
            {
                head1=node;
                curr=node;
            }
            else
            {
           
            curr->next=node;

            curr=node;
            }
        }

        return head1; 
    }
};