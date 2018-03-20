/**
 * 36ms
 * Like my map version
 * But priority queue can define self compare method
 * so it can store struct ListNode* directly, cleaner
 */

class Solution{
    struct cmp{
        bool operator () (ListNode *l1, ListNode *l2){
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode *>& lists){
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for(auto e : lists){
            if(e)
                q.push(e);
        }
        ListNode* head = new ListNode(0), *tail = head;
        while(!q.empty()){
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next)
                q.push(tail->next);
        }
        return head->next;
    }
};
