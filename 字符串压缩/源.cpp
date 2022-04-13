#include<string>
#include<iostream>
using namespace std;
string compressString(string S) {
	string x = "";
	int k = 1;
	string g = "";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == S[i + 1]) {
			k++;
		}
		else {
			x.push_back(S[i]);
			g = to_string(k);
			x += g;
			k = 1;
		}
	}
	if (x.size() >= S.size())
		return S;
	else 
		return x;
}
void main() {
	string S = "aabcccccaaa";
	cout<<compressString(S)<<endl;
}