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
    ListNode* swapPairs(ListNode* head){
        ListNode *dummy = new ListNode(0), *tail = dummy;
        while(head && head->next){
			ListNode *first = head;
			ListNode *second = head->next;
			head  = second->next;

			second->next = first;
			first->next = head;

			tail->next = second;
			tail->next->next = first;
			tail = tail->next->next;
        }
        tail->next = head;
        return dummy->next;
    }
};
