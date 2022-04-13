//ʵ��RandomizedSet �ࣺ
//
//RandomizedSet() ��ʼ�� RandomizedSet ����
//bool insert(int val) ��Ԫ�� val ������ʱ���򼯺��в����������� true �����򣬷��� false ��
//bool remove(int val) ��Ԫ�� val ����ʱ���Ӽ������Ƴ���������� true �����򣬷��� false ��
//int getRandom() ����������м����е�һ�����������֤���ô˷���ʱ���������ٴ���һ��Ԫ�أ���ÿ��Ԫ��Ӧ���� ��ͬ�ĸ��� �����ء�
//�����ʵ��������к�����������ÿ�������� ƽ�� ʱ�临�Ӷ�Ϊ O(1) ��
//
//
//
//ʾ����
//
//����
//["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
//[[], [1], [2], [2], [], [1], [2], []]
//���
//[null, true, false, true, 2, true, false, 2]
//
//����
//RandomizedSet randomizedSet = new RandomizedSet();
//randomizedSet.insert(1); // �򼯺��в��� 1 ������ true ��ʾ 1 ���ɹ��ز��롣
//randomizedSet.remove(2); // ���� false ����ʾ�����в����� 2 ��
//randomizedSet.insert(2); // �򼯺��в��� 2 ������ true ���������ڰ��� [1,2] ��
//randomizedSet.getRandom(); // getRandom Ӧ������� 1 �� 2 ��
//randomizedSet.remove(1); // �Ӽ������Ƴ� 1 ������ true ���������ڰ��� [2] ��
//randomizedSet.insert(2); // 2 ���ڼ����У����Է��� false ��
//randomizedSet.getRandom(); // ���� 2 �Ǽ�����Ψһ�����֣�getRandom ���Ƿ��� 2 ��
//
//
//��ʾ��
//
//- 231 <= val <= 231 - 1
//������ insert��remove �� getRandom ���� 2 * 105 ��
//�ڵ��� getRandom ����ʱ�����ݽṹ�� ���ٴ���һ�� Ԫ�ء�
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