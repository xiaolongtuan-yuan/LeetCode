#include<iostream>//不能这么做，当所求链表特别长时，无法进行加法，应该重写加法器
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//	ListNode* k1 = l1;
//	ListNode* k2 = l2;
//	long int n1 = 0, n2 = 0;
//	long int a = 1;
//
//	while (k1) {
//		n1 += k1->val * a;
//		a *= 10;
//		k1 = k1->next;
//	}
//	a = 1;
//	while (k2) {
//		n2 += k2->val * a;
//		a *= 10;
//		k2 = k2->next;
//	}
//	long int n3 = n1 + n2;
//	int m = 0;
//	ListNode* k3;
//	m = n3 % 10;
//	k3 = new ListNode(m);
//	n3 = n3 / 10;
//	ListNode* k5 = k3;
//	ListNode* k4;
//	while (n3 > 0) {
//		m = n3 % 10;
//		k4 = new ListNode(m);
//		n3 = n3 / 10;
//		k5->next = k4;
//		k5 = k4;
//	}//k5和k4都指向最后一个节点
//	/*k5 = k3;
//	k4 = k3->next;
//	while (k4) {
//		k5->next = k4->next;
//		k4->next = k3;
//		k3 = k4;
//		k4 = k5->next;
//	}*///用于倒置链表，这里不需要了
//	return k3;
//}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* k1 = l1;
	ListNode* k2 = l2;
	ListNode l3(0);
	ListNode* k3 = &l3;
	int t = 0;//进位
	int s = 0;//结果
	while (k1&&k2) {//k1,k2不为null
		s = k1->val + k2->val + t;
		if (s >= 10) {
			t = 1;
			s = s % 10;
		}
		else {
			t = 0;
		}
		k3->next = new ListNode(s);
		k3 = k3->next;
		k1 = k1->next;
		k2 = k2->next;
	}
	if (k1) {
		while (k1) {//k2空
			k3->next = k1;
			s = k1->val + t;
			if (s >= 10) {
				t = 1;
				s = s % 10;
			}
			else {
				t = 0;
			}
			k1->val = s;
			k3 = k1;
			k1 = k1->next;
		}
		if (t == 1) {
			ListNode a(1);
			k3->next = &a;
		}
	}
	else if(k2) {
		while (k2) {//k1空
			k3->next = k2;
			s = k2->val + t;
			if (s >= 10) {
				t = 1;
				s = s % 10;
			}
			else {
				t = 0;
			}
			k2->val = s;
			k3 = k2;
			k2 = k2->next;
		}
		if (t == 1) {
			ListNode a(1);
			k3->next = &a;
		}
	}
	else {//k1,k2均为空
		if (t == 1) {
			k3->next = new ListNode(1);
		}
	}
	return l3.next;
}


//[9]
//[1, 9, 9, 9, 9] = [0,0,0,0,0,1]
//[2, 4, 3]
//[5, 6, 4]
void main() {

	//ListNode a = ListNode(9);

	//ListNode b = ListNode(9);
	//ListNode c = ListNode(9);
	//c.next = &b;
	//ListNode d = ListNode(9);
	//d.next = &c;
	//ListNode e = ListNode(9);
	//e.next = &d;
	//ListNode f = ListNode(9);
	//f.next = &e;
	//ListNode g = ListNode(9);
	//g.next = &f;
	//ListNode h = ListNode(9);
	//h.next = &g;
	//ListNode i = ListNode(9);
	//i.next = &h;
	//ListNode j = ListNode(9);
	//j.next = &i;
	//ListNode k = ListNode(1);
	//k.next = &j;
	ListNode b = ListNode(1);

	ListNode e = ListNode(9);
	ListNode f = ListNode(9);
	f.next = &e;
	//ListNode* t = addTwoNumbers(&a,&f);
	ListNode* t = addTwoNumbers(&b, &f);
	return;
}