#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
   
	int count[10000] = { 0, }; // counting sort  10,000���� �۰ų� ���� �ڿ���
	int N, x, max = 0; // ���� ū �������� ����ϱ� ���� max ���� 

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		count[x - 1]++; // ������ �ڿ��� x�� x-1 �ڸ��� ����
		if (max < x) // max �� Ȯ��
			max = x;
	}
	for (int i = 0; i < max; i++) { //max ������  
		if (count[i] != 0) {  // count sort�� �� ���� �ƴ� ���
			for (int j = 0; j < count[i]; j++) { // ��(Ƚ��) ��ŭ ���
				cout << (i + 1) << '\n';
			}
		}
	}
	return 0;
}