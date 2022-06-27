/*#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

bool pri_num[10001]; 
int visited[10001]; // ���غ� ��й�ȣ Ȯ��
int y;

void prime() { // 1000~9999 �� �� �Ҽ��� ture
	int pri = 1;
	for (int i = 1000; i < 10000; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				pri_num[i] = false;
				continue;
			}
		}
	}
}
void bfs(int num) {

	queue<int> q;
	q.push(num);

	visited[num] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i<4; i++) {

			string node_s = to_string(node); // ���ڿ��� ����
	
			for (int j = 0; j < 10; j++) { // 0~10 ��ȯ�ؼ� Ȯ��
		 
				node_s[i] = j + '0';

				int next = stoi(node_s); 

				if (next >= 1000 && pri_num[next] == true && visited[next] == -1) { // visited Ȯ���ϸ鼭 q�� ����
					visited[next] = visited[node] + 1;
					q.push(next);
				}
			}
		}
	}
}
int main() {

	int T, x;

	cin >> T;

	memset(pri_num, true, sizeof(pri_num));
	prime();

	for (int t = 0; t < T; t++) {

		memset(visited, -1, sizeof(visited)); // -1 �� �ʱ�ȭ

		cin >> x >> y;
		bfs(x);

		if (visited[y] != -1) { 
			printf("%d\n", visited[y]);
		}
		else {
			printf("Impossible\n");
		}
	}

	return 0;
}*/