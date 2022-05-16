#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, x, y;
	priority_queue<int> pq;

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> x;

		if (x == 0) { // ������ ���� ���� x ������ Ȯ��
			if (pq.empty()) { //0�̸� �� ť�� �� -1 ���
				cout << -1 << "\n"; 
				}
			else { // �ƴ� �� top �� ��� �� pop
				cout << pq.top() << "\n";
				pq.pop();
				}
		}
		else {
			for (int j = 0; j < x;  j++) { // ������ ���� x ���̸�
				cin >> y; // x �� ��ŭ for������ ť�� �ֱ�
				pq.push(y);
			}
		}
	}
	return 0;
}