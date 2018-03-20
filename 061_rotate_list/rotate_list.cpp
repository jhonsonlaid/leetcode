/**
 * Definition for singly-linked list.
 * struct ListNode{
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL){}
 * };
 */

class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        ListNode dumb(0), *tail, *joint;
        dumb.next = head;
        int len = 0;
        // get list len
        for(tail = &dumb; tail->next != NULL; len++)
            tail = tail->next;
        joint = &dumb;
        k = len ? k % len : 0;
        for(int i = 0; i < len - k; i++){
            joint = joint->next;
        }
        ListNode *new_head = joint->next ? joint->next : head;
        if(k != len)
            tail->next = head;
        joint->next = NULL;
        return new_head;
    }
};
