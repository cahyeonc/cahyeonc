#include <cstdio>
#include <iostream>
#include <queue>
#include <vector> //�迭ó�� ���

using namespace std;

int main() {

	int N, M;
	int total = 0;
	queue<int> wait; //��ٸ��� ��
	vector<int> park; //������
	vector<int> Wk;  //��������
	vector<int> Rs; //�������� ���

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		Rs.insert(Rs.begin() + i, p);  //Rs = [ 2, 3, 5 ]
		park.insert(park.begin()+i, 0); //������ ����Ȯ�� (�� 0 = ���ڸ�)
	}
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;
		Wk.insert(Wk.begin() + i, c);  //Wk = [ 200, 100, 300, 800 ]
	}

	for (int i = 0; i < M * 2; i++) {
		int parking;
		cin >> parking;

		if (parking > 0) { //������ ��
			int w = 1;
			for (int j = 0; j < N; j++) { // park(������) ���� ���ڸ����� Ȯ��
				if (park[j] == 0) { //�� ���� ����
					park[j] = parking;
					w = 0; //�������� �� waiting ����
					break;
				}
			}
			if (w == 1) { //waiting ���� �� waitť�� push
				wait.push(parking);
			}
		}
		else{ //������ ��
			for (int j = 0; j < N; j++) {
				if (park[j] == parking * (-1)) { //������ �� �ڸ� ã�Ƽ� 
					total += Rs[j] * Wk[parking * (-1)-1]; // ����������� * ���� ����ؼ� total�� ��ħ
					
					park[j] = 0; // �����ڸ� ������� ����
					if (!wait.empty()) { // ��ٸ��� ���� ���� �� 
						park[j] = wait.front(); //ó�� ��ٸ� ���� �������ڸ��� �ְ�
						wait.pop(); //waitť���� ���� 
					}
					break;
				}
			}
		}
	}
	cout << total;
	return 0;
}