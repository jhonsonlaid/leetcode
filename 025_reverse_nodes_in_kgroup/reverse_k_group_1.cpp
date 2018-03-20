class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode *dummy = new ListNode(0), *tail = dummy,
                 *pre = dummy, *cur;

        dummy->next = head;

        while(true){
            for(int i = 0; i < k && tail; i++){
                tail = tail->next;
            }
            if(i < k-1) break;

            head = pre->next; // next new head is current node, i.e. pre->next

            while(pre->next != tail){
            cur = pre->next; // get current node
            pre->next = cur->next; // pre -->(point to) next node 
            cur->next = tail->next; // cur --> tail->next
            tail->next = cur; // insert cur to tail
            }

            pre = head;
            tail = head;
        }
            return dummy->next;
        
    }
};
