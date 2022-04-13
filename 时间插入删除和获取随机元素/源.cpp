//实现RandomizedSet 类：
//
//RandomizedSet() 初始化 RandomizedSet 对象
//bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
//bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
//int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
//你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
//
//
//
//示例：
//
//输入
//["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
//[[], [1], [2], [2], [], [1], [2], []]
//输出
//[null, true, false, true, 2, true, false, 2]
//
//解释
//RandomizedSet randomizedSet = new RandomizedSet();
//randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
//randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
//randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
//randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
//randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
//randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
//randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
//
//
//提示：
//
//- 231 <= val <= 231 - 1
//最多调用 insert、remove 和 getRandom 函数 2 * 105 次
//在调用 getRandom 方法时，数据结构中 至少存在一个 元素。
#include<vector>
#include<map>
#include<ctime>
#include<cstdlib>
using namespace std;


class RandomizedSet {
public:
	vector<int> a;
	map<int, int> b;

	RandomizedSet() {
	}

	bool insert(int val) {
		if (b.find(val) == b.end()) {
			b.insert({ val,a.size() });
			a.push_back(val);
			return true;
		}
		else
			return false;
	}

	bool remove(int val) {
		if (b.find(val) == b.end()) {
			return false;
		}
		else {
			int t = b[val];
			a[t] = a[a.size()-1];
			b[a.size() - 1] = t;
			a.pop_back();
			b.erase(val);
			return true;
		}
	}

	int getRandom() {
		int x = rand() % (a.size());
		return a[x];
	}

};
// RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"
//["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]
//["RandomizedSet", "insert", "insert", "remove", "insert", "remove", "getRandom"]
//[[], [0], [1], [0], [2], [1], []]
int main() {
	RandomizedSet p;
	p.insert(0);
	p.insert(1);
	p.remove(0);
	p.insert(2);
	p.remove(1);
	p.getRandom();

	return 0;
}