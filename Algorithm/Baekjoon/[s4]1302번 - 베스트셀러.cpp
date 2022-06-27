#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main() {

	map<string, int> m;
	int n, Vmax=0;
	string x, Kmax;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (m.count(x)) { // Ű ������ +1
			m[x] += 1;
		}
		else { // ������ �߰�
			m[x] = 1;
		}
	}

	for (auto j : m) { // �ʾ��� ���ҵ� value max ã��
		if (Vmax < j.second) {
			Vmax = j.second;
			Kmax = j.first;
		}
	}
	cout << Kmax;

	return 0;
}