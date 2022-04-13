#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
	int h = matrix.size();
	int w = matrix[0].size();
	bool *I = new bool[h];
	memset(I, false, h);
	
	bool *J = new bool[w];
	memset(J, false, w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (matrix[i][j] == 0) {
				I[i] = true;
				J[j] = true;
			}
		}
	}
	for (int k = 0; k < h; k++) {
		if (I[k]) {
			for (int n = 0; n < w; n++)
				matrix[k][n] = 0;
		}
	}
	for (int k = 0; k < w; k++) {
		if (J[k]) {
			for (int n = 0; n < h; n++)
				matrix[n][k] = 0;
		}
	}
	delete[] I;
	delete[] J;
}
void main() {
	vector<vector<int>>m = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
	setZeroes(m);
}