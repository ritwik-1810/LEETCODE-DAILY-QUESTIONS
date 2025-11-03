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
    ListNode* removeNodes(ListNode* head) {

        vector<int>vec;

        ListNode* temp=head;

        while(temp)
        {
            vec.push_back(temp->val);

            temp=temp->next;
        }

        int size = vec.size();

        vector<int>next_gre(size,-1);

        stack<int>st;

        st.push(0);

        for(int i=1;i<size;i++)
        {
            while(!st.empty() && vec[st.top()]<vec[i])
            {
                int idx=st.top();

                st.pop();

                next_gre[idx]=vec[i];
            }

            st.push(i);
        }

        while(!st.empty())
        {
            next_gre[st.top()]=-1;

            st.pop();
        }

        temp=head;

        ListNode* prev=NULL;

        int i=0;

        while(temp)
        {
            if(next_gre[i]!=-1)
            {
               if(temp==head)
               {
                  head=temp->next;

                 // delete(temp);

                  temp=head;
               } 
               else
               {
                  prev->next=temp->next;

                  //delete(temp);

                  temp=prev->next;
               }
           
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }

            i++;

        }

       return head;
    
    }
};