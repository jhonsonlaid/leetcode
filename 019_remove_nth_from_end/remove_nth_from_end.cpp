/**
 * Using vector to store ListNode pointer,
 * Not good enough
 * Definition for singly-linked list.
 * struct ListNode{
 *      int val;
 *      ListNode* next;
 *      ListNode(int x): val(x), next(NULL) {}
 * }
 */

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* ele = head;
        vector<ListNode*> node_list;
        while(ele){
			node_list.push_back(ele);
			ele = ele->next;
        }
		int ns = node_list.size();
		if( n < ns && n > 1)
			node_list[ns-n-1]->next = node_list[ns-n+1];
		else if(1 == n)
            if(ns-n-1 >= 0)
			    node_list[ns-n-1]->next = NULL;
            else 
                return NULL;
		else if(n == ns){
			return node_list[1];
		}
		return head;
    }
};
