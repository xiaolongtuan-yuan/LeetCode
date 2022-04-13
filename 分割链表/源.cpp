#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* head, int x) {
	if (head != NULL) {
		ListNode* first = head;
		ListNode* last = head;
		ListNode* h = head;
		while (first) {
			if (first->val > x || first->val == x) {
				h = first;
				first = first->next;
			}
			else {
				h->next = first->next;
				first->next = last->next;
				last->next = first;
				first = h->next;
				last = last->next;
			}
		}
	}
	return head;
	//ListNode* m = new ListNode(0);//比x大
	//ListNode* m_next = m;
	//ListNode* n = new ListNode(0); //比x小
	//ListNode* n_next = n;
	//ListNode* k = head->next;
	//while (k) {
	//	if (k->val > x || k->val == x) {
	//		ListNode* h = new ListNode(k->val);
	//		m_next->next = h;
	//		m_next = m_next->next;
	//	}
	//	else {
	//		ListNode* h = new ListNode(k->val);
	//		n_next->next = h;
	//		n_next = n_next->next;
	//	}
	//	k = k->next;
	//}
	//n_next->next = m->next;
	//delete m;
	//return n;
}
//[1,4,3,2,5,2]
void main() {

	ListNode a = ListNode(2);
	ListNode b = ListNode(5);
	b.next = &a;
	ListNode c = ListNode(2);
	c.next = &b;
	ListNode d = ListNode(3);
	d.next = &c;
	ListNode e = ListNode(4);
	e.next = &d;
	ListNode f = ListNode(1);
	f.next = &e;

	ListNode*t = partition(&f,3);
	return;
}