#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}//类似于构造函数
};
ListNode* removeDuplicateNodes(ListNode* head) {
	ListNode *k = head;
	vector<int> x;
	ListNode *temp = head;
	while (k) {
		if (find(x.begin(),x.end(),k->val)==x.end()) {
			x.push_back(k->val);
			temp = k;
			k = k->next;
		}
		else {
			k = k->next;
			temp->next = k;
		}
	}
	return head;
}
//283, 263, 68, 245, 324, 128, 279
void main() {
	ListNode a(283);
	ListNode b(263);
	a.next = &b;
	ListNode c(68);
	b.next = &c;
	ListNode d(245);
	c.next = &d;
	ListNode e(324);
	d.next = &e;
	ListNode f(128);
	e.next = &f;
	ListNode g(279);
	f.next = &g;
	removeDuplicateNodes(&a);
	return;
}