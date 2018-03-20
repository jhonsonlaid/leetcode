/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;

        while(true){
            if(!l1 && !l2){
                return NULL;
            }
            else if(!l1){
                tail->next = l2;
                break;
            }
            else if(!l2){
                tail->next = l1;
                break;
            }
            else if(l1->val < l2->val){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
