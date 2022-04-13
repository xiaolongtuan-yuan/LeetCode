#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
	int *sever = new int[k]();//记录每个服务器开始工作的时间
	int *sever_w = new int[k]();//记录每个服务器的工作情况
	int *sever_n = new int[k]();//记录每个服务器的服务数量
	int s = 0;//指向当前服务器
	for (int i = 0; i < arrival.size(); i++) {
		if (i < k) {
			sever[s] = arrival[i];
			sever_w[s] = load[i];
			sever_n[s]++;
			s = (s + 1) % k;
		}//前k个直接运行
		else {
			s = i % k;
			int time = sever_w[s] - (arrival[i] - sever[s]);//只计算时间差不改变sever_w
			int n = k;
			while (time > 0) {//查看下一个服务器
				n--;
				if (n == 0)
					break;
				s = (s + 1) % k;
				time = sever_w[s] - (arrival[i] - sever[s]);
			}
			if (n == 0)
				continue;//放弃当前任务
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
方法一: 模拟 + 有序集合 + 优先队列
思路与算法

将空闲服务器的编号都放入一个有序集合available 中，将正在处理请求的服务器的处理结束时间和编号都放入
一个优先队列busy 中，优先队列满足队首的服务器的处理结束时间最小，用一个数组 requests 记录对应服务器
处理的请求数目。
假设当前到达的请求为第 ii 个，如果busy 不为空， 那么我们判断busy 的队首对应的服务器的结束时间是否小
于等于当前请求的到达时间arrival[i]，如果是，那么我们将它从busy 中移除，并且将该服务器的编号放入available
中，然后再次进行判断。如果available 为空，那么该请求被丢弃；否则查找available 中大于等于 i % k 的第
一个元素，如果查找成功，那么将它作为处理请求的服务器，否则将available 中编号最小的服务器作为处理请求
的服务器。设处理请求的服务器的编号为 j，那么将requests[j] 加 1，并且将该服务器从available 移除，然后
将服务器 j 放入busy 中，对应的处理结束时间为arrival[i]+load[i]。

获取requests 的最大值 maxRequest，遍历 requests 数组，对于每个下标 i，如果requests[i]=maxRequest，那
么将编号 i 加入结果中。

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