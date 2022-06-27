#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k;
	queue<int> q;
	vector<int> v;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int b = 0;
	int a = 1;
	while (1) {
		if (q.empty()) { // ť�� ����� �� while ������
			break;
		}
		if (a == k) { // k��° �ڸ� �� pop()�ϸ鼭 ���Ϳ� ����
			v.insert(v.begin() + b, q.front());	// ���ŵǴ� ������ �迭 ����
			q.pop();
			a = 1; // �ڸ� 1�� �ʱ�ȭ
			b++; //�����ε��� ++
			continue;
		}
		else { // k��° �ڸ��� �ƴϸ� push - pop		
			q.push(q.front());
			q.pop();
			a++;//�ڸ� ����
		}
	}
	//----------------���� ���
	printf("<%d", v[0]);
	for (int j = 1; j < b; j++) {

		printf(", %d", v[j]);
	}
	printf(">");
}


