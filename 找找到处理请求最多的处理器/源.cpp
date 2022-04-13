#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
	int *sever = new int[k]();//��¼ÿ����������ʼ������ʱ��
	int *sever_w = new int[k]();//��¼ÿ���������Ĺ������
	int *sever_n = new int[k]();//��¼ÿ���������ķ�������
	int s = 0;//ָ��ǰ������
	for (int i = 0; i < arrival.size(); i++) {
		if (i < k) {
			sever[s] = arrival[i];
			sever_w[s] = load[i];
			sever_n[s]++;
			s = (s + 1) % k;
		}//ǰk��ֱ������
		else {
			s = i % k;
			int time = sever_w[s] - (arrival[i] - sever[s]);//ֻ����ʱ���ı�sever_w
			int n = k;
			while (time > 0) {//�鿴��һ��������
				n--;
				if (n == 0)
					break;
				s = (s + 1) % k;
				time = sever_w[s] - (arrival[i] - sever[s]);
			}
			if (n == 0)
				continue;//������ǰ����
			sever_n[s]++;
			sever[s] = arrival[i];
			sever_w[s] = load[i];
			s = (s + 1) % k;
		}
	}
	int max_s = 0;
	vector<int> ret;
	for (int i = 0; i < k; i++) {
		max_s = max(max_s, sever_n[i]);
	}
	for (int i = 0; i < k; i++) {
		if (sever_n[i] == max_s)
			ret.push_back(i);
	}
	return ret;
}
void main() {
	vector<int> a = { 3, 4, 6, 8, 9, 11, 12, 16 };
	vector<int> b = { 1, 2, 8, 6, 5, 3, 8, 3 };
	vector<int> c = busiestServers(3, a, b);
}
//3
//[3, 4, 6, 8, 9, 11, 12, 16]
//[1, 2, 8, 6, 5, 3, 8, 3]

/*
����һ: ģ�� + ���򼯺� + ���ȶ���
˼·���㷨

�����з������ı�Ŷ�����һ�����򼯺�available �У������ڴ�������ķ������Ĵ������ʱ��ͱ�Ŷ�����
һ�����ȶ���busy �У����ȶ���������׵ķ������Ĵ������ʱ����С����һ������ requests ��¼��Ӧ������
�����������Ŀ��
���赱ǰ���������Ϊ�� ii �������busy ��Ϊ�գ� ��ô�����ж�busy �Ķ��׶�Ӧ�ķ������Ľ���ʱ���Ƿ�С
�ڵ��ڵ�ǰ����ĵ���ʱ��arrival[i]������ǣ���ô���ǽ�����busy ���Ƴ������ҽ��÷������ı�ŷ���available
�У�Ȼ���ٴν����жϡ����available Ϊ�գ���ô�����󱻶������������available �д��ڵ��� i % k �ĵ�
һ��Ԫ�أ�������ҳɹ�����ô������Ϊ��������ķ�����������available �б����С�ķ�������Ϊ��������
�ķ��������账������ķ������ı��Ϊ j����ô��requests[j] �� 1�����ҽ��÷�������available �Ƴ���Ȼ��
�������� j ����busy �У���Ӧ�Ĵ������ʱ��Ϊarrival[i]+load[i]��

��ȡrequests �����ֵ maxRequest������ requests ���飬����ÿ���±� i�����requests[i]=maxRequest����
ô����� i �������С�

class Solution {
public:
	vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
		set<int> available;
		for (int i = 0; i < k; i++) {
			available.insert(i);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
		vector<int> requests(k);
		for (int i = 0; i < arrival.size(); i++) {
			while (!busy.empty() && busy.top().first <= arrival[i]) {
				available.insert(busy.top().second);
				busy.pop();
			}
			if (available.empty()) {
				continue;
			}
			auto p = available.lower_bound(i % k);
			if (p == available.end()) {
				p = available.begin();
			}
			requests[*p]++;
			busy.emplace(arrival[i] + load[i], *p);
			available.erase(p);
		}
		int maxRequest = *max_element(requests.begin(), requests.end());
		vector<int> ret;
		for (int i = 0; i < k; i++) {
			if (requests[i] == maxRequest) {
				ret.push_back(i);
			}
		}
		return ret;
	}
};
*/