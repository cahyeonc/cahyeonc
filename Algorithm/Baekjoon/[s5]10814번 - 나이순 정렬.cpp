/*#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v[201]; // ���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� ����

	int N, x;
	string s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> s;
		v[x].push_back(s); // �ε���(����)�� �̸� ����
	}

	for (int i=1; i<=200; i++) {
		for (int j=0; j < v[i].size(); j++) { // ���̰� ������ ���� ������ ����� �տ� ���� ����
			cout << i << ' ' << v[i][j] << '\n';
		}
	}
	return 0;
}*/