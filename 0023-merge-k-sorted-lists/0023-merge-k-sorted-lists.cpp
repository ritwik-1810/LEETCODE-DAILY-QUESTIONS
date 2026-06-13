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
            ListNode* head=lists[i];
            
            if(head!=nullptr)
            pq.push({head->val,head});
        }

        if(pq.empty()) return nullptr;

        ListNode* fr=pq.top().second;
        
        ListNode* temp=fr;

        pq.pop();

        while(!pq.empty())
        {
            if(temp->next==nullptr)
            {
               temp->next=pq.top().second;

               temp = temp->next;

               pq.pop();
            }
            else
            {
               ListNode* er=temp->next;
               
               if(er->val>pq.top().first)
               {
                  temp->next=pq.top().second;

                  pq.pop();

                  pq.push({er->val,er});
               }
               else
               {
                  temp=temp->next;
               }

            }
        }

        return fr;

    }
};