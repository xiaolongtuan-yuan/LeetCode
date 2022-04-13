//我们要把给定的字符串 S 从左到右写到每一行上，每一行的最大宽度为100个单位，如果我们在写某个字母的时候会使这行超过了100 个单位，那么我们应该把这个字母写到下一行。我们给定了一个数组 widths ，这个数组 widths[0] 代表 'a' 需要的单位， widths[1] 代表 'b' 需要的单位，...， widths[25] 代表 'z' 需要的单位。
//
//现在回答两个问题：至少多少行能放下S，以及最后一行使用的宽度是多少个单位？将你的答案作为长度为2的整数列表返回。

#include<iostream>
#include<vector>
#include<string>

using namespace std;
int index(char a) {
	return (int(a) - 97);
}
vector<int> numberOfLines(vector<int>& widths, string s) {
	int len = 0;
	int lins = 1;
	for (int i = 0; i < s.length(); i++) {
		len += widths[index(s.at(i))];
		if (len < 100)
			continue;
		else {
			len = widths[index(s.at(i))];
			lins++;
		}

	}
	vector<int> res;
	res.push_back(lins);
	res.push_back(len);
	return res;
}
void main() {
	string s = "bbbcccdddaaa";
	vector<int> widths = { 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	numberOfLines(widths, s);
}