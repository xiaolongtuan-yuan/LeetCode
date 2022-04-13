#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
bool canPermutePalindrome(string s) {
	string t = s;
	char c;
	if (t.length() % 2 == 0) {
		for (int i = 0; i < s.length() / 2; i++) {
			c = t[0];
			t = t.erase(0, 1);
			if (t.find(c) == -1) {
				return false;
			}
			else {
				t = t.erase(t.find(c), 1);
			}
		}
		return true;
	}
	else {//ÆæÊý¸ö×Ö·û
		bool flag = false;
		for (int i = 0; i < (s.length() + 1) / 2; i++) {
			c = t[0];
			t = t.erase(0, 1);
			if (t.find(c) == -1 && flag) {
				return false;
			}
			else if (t.find(c) == -1 && !flag) {
				flag = true;
			}
			else {
				t = t.erase(t.find(c), 1);
			}
		}
		return true;
	}
}
void main() {
	string s;
	cin >> s;
	cout << canPermutePalindrome(s) << endl;
}