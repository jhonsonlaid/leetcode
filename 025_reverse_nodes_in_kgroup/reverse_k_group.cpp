class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int k){
        ListNode *dummy = new ListNode(0), *tail = dummy, *old_tail = dummy;
        vector<ListNode*> lv;
        int i = 0;
        while(lv.size() < k && head)
            lv.push_back(head);
            tail->next = head;
            head = head->next;
            tail = tail->next;
        }
        while(lv.size() == k){
            for(int j = k-1; j > 0; j++){
                lv[j]->next = lv[j-1];
            }
            old_tail->next = lv[k-1];
            old_tail = lv[0];
            tail = lv[0];
            lv.clear();
            while(lv.size() < k && head){
                lv.push_back(head);
                tail->next = head;
                head = head->next;
                tail = tail->next;
            }
        }
        return dummy->next;
    }
};
