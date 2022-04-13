#include<iostream>
#include<string>
using namespace std;

bool isFlipedString(string s1, string s2) {
	if (s1.size() != s2.size())
		return false;
	else {
		string temp = "";
		bool flag = false;
		for (int i = 0, j = 0; i < s1.size() && j < s1.size(); i++, j++) {
			if (s1[i] != s2[j] && !flag) {
				temp.push_back(s1[i]);
				j--;
			}
			else if (s1[i] == s2[j] && !flag) {
				s1 += temp;
				flag = true;
			}
			else if (s1[i] != s2[j] && flag) {
				return false;
			}
		}
		return true;
	}
}
void main() {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	cout<<isFlipedString(s1, s2);
}