/* struct指针的两种初始化方法
 * 指向一个struct object：ListNode lHead(0); ListNode* ptr = &lHead;
 * 使用new：ListNode* ptr = new ListNode(0);
 * C的方法：struct ListNode* ptr = 
 *              (struct ListNode*)malloc(sizoef(struct ListNode));
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode lHead(0);
        ListNode* lres= &lHead;
		int carry = 0;
        while(l1 || l2 || carry)
        {
			int l1v = l1 ? l1->val : 0;
			int l2v = l2 ? l2->val : 0;
			int sum = l1v + l2v + carry;

            lres->next = new ListNode(sum % 10);
            lres = lres->next;

            carry = sum/10 ? 1: 0;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
	return lHead.next;
    }
};
