/**
 * 26ms, using hash table
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
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;

		// pair(number, vector(list_index));
        map<int, vector<int> > kt;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                kt[lists[i]->val].push_back(i);
        }

        while(kt.size() > 0){
            vector<int>::iterator it;
            vector<int> min_vec(kt.begin()->second);
            for(it = min_vec.begin(); it != min_vec.end(); it++){
                tail->next = lists[*it];
                tail = tail->next;
                lists[*it] = lists[*it]->next;
            }

			// delete min num
            kt.erase(kt.begin());

            // if the list that contains min_num size > 0 
			// then insert new element to hash table 
            for(int i = 0; i < min_vec.size(); i++){
                if(lists[min_vec[i]])
                    kt[lists[min_vec[i]]->val].push_back(min_vec[i]);
            }
        }
        return head->next;
    }
};
