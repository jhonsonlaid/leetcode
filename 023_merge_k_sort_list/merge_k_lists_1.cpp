/**
 * 36ms
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x): val(x), next(NULL){}
 * };
 */

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode *>& lists){
        ListNode* tail = new ListNode(0), *head = tail;

        vector<int> vec;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i]){
                vec.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(vec.begin(), vec.end());
        for(int j = 0; j < vec.size(); j++){
            tail->next = new ListNode(vec[j]);
            tail = tail->next;
        }
        return head->next;
    }
};
