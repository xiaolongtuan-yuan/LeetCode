#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
bool oneEditAway(string first, string second) {
	int d = first.length() - second.length();
	if (d > 1 || d < -1)//相差大于2个字符
		return false;
	else {
		int c = 1;
		for (int i=0, j = 0; i < first.size()&&j < second.size(); i++, j++) {
			if (first[i] != second[j]) {
				if (d == 1) {
					j--;
					c--;
				}
				else if (d == -1) {
					i--;
					c--;
				}
				else {
					c--;
				}
			}
		}
		if (c < 0)
			return false;
		else
			return true;
	}
}
int main() {
	string s1 = "islander";
	string s2 = "slander";
	cout << oneEditAway(s1, s2);
}