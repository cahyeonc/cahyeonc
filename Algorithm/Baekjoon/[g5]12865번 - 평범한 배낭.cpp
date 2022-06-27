/*#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K, w, v, result = 0;

	cin >> N >> K;

	vector<pair<int, int>> bag(N); //����
	vector<int> dp_w[101]; // ����
	vector<int> dp_v[101]; // ��ġ

	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		bag[i] = pair<int, int> (w, v);
	}

	dp_w[0].push_back(bag[0].first); // �� ó�� ����
	dp_v[0].push_back(bag[0].second);

	for (int a = 1; a < N; a++) {

		for (int i = 0; i < a ; i++) {

			dp_w[a].push_back(bag[a].first + bag[i].first); // ù��° ����
			dp_v[a].push_back(bag[a].second + bag[i].second);

			for (int j = 0; j < dp_v[i].size(); j++) {
				int x = 0;

				if (bag[a].first + dp_w[i][j] <= K) { // ���ǵ��� ���� ���Ը� ���� dp�� ���ʴ�� ��
					dp_w[a].push_back(bag[a].first + dp_w[i][j]);
					dp_v[a].push_back(bag[a].second + dp_v[i][j]);
					x = bag[a].second + dp_v[i][j];
				}
				else { // K���� ũ�� �׳� �ڽ��� ���Կ� ��ġ�� ����
					dp_w[a].push_back(bag[a].first);
					dp_v[a].push_back(bag[a].second);
					x = bag[a].second;
				}
				if(result < x){
					result = x;
				}
			}
		}
	}
	cout << result;

	return 0;
}*/