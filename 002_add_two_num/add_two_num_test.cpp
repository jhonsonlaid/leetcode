/*** Two Sum using Hashtable ***/
/*** jhonsonlaid@gmail.com ***/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main()
{
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next = new ListNode(4);

	Solution s1;
	ListNode* lres = s1.addTwoNumbers(l1, l2);
	std::cout << lres->val << std::endl;
	system("pause");
	return 0;
}
