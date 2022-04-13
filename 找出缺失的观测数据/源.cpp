#include<iostream>
#include<vector>
using namespace std;
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
	int sum1 = 0;
	for (int x : rolls) {
		sum1 += x;
	}
	int sum2 = (rolls.size() + n)*mean;
	int min = sum1 + n;
	int max = sum1 + n * 6;
	vector<int> rolls2;
	if (sum2<min || sum2>max)
		return rolls2;
	else {
		for (int i = 0; i < n; i++) {
			rolls2.push_back(1);
		}
		int gap = sum2 - min;
		int i = 0;
		while (gap > 0) {
			if (i < n) {
				rolls2[i]++;
			}
			else {
				i = 0;
				rolls2[i]++;
			}
			i++;
			gap--;
		}
		return rolls2;
	}
}
void main() {
	vector<int>rolls = {3, 2, 4, 3};
	vector<int>rolls2 = missingRolls(rolls, 4, 2);
	for(int x : rolls2)
		cout << x << " ";
	return;
}