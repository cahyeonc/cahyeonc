#include <iostream>
#include <queue>
#include <functional> // greater

using namespace std;

priority_queue<int, vector<int>, greater<int>> u_pq; //�������� ������ ����(���)
priority_queue<int> d_pq; //�������� ū�� ����(����)

void func () {
	if (u_pq.empty() & d_pq.empty()) {
		cout << "0\n";
	}
	else if(u_pq.empty()){
		cout << d_pq.top() << "\n";
		d_pq.pop();
	}
	else if (d_pq.empty()) {
		cout << u_pq.top() << "\n";
		u_pq.pop();
	}
	else {
		if (abs(u_pq.top()) >= abs(d_pq.top())) {

			cout << d_pq.top() << "\n";
			d_pq.pop();
		}
		else {
			cout << u_pq.top() << "\n";
			u_pq.pop();
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	int N, x;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) { // 0 �϶�
			func();
		}
		else if (x > 0) { // ����� �� u_pd
			u_pq.push(x);
		}
		else {
			d_pq.push(x); // ������ �� d_pq
		}
	}
	return 0;
}