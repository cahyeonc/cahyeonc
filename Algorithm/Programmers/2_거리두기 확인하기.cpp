#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool BFS(int a, int b, vector<string> room)
{
	vector<vector<bool>> visit(5, vector<bool>(5, false));
	queue<pair<pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(a, b), 0));
	visit[a][b] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first.first; // P ������ ��ġ
		int y = Q.front().first.second;
		int Cnt = Q.front().second; // 2���� Ȯ��
		Q.pop();

		if (Cnt == 2) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i]; // ������ġ
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
			{
				if (visit[nx][ny] == false)
				{
					if (room[nx][ny] == 'O') // �� ���̺�
					{
						visit[nx][ny] = true;
						Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
					}
					else if (room[nx][ny] == 'P') // ������
					{
						return false;
					}
				}

			}
		}
	}
	return true; // ĭ���� �Ǵ� ������ x
}

int Rooms(vector<string> room)
{
	for (int i = 0; i < room.size(); i++)
	{
		for (int j = 0; j < room[i].size(); j++)
		{
			if (room[i][j] == 'P')
			{
				if (BFS(i, j, room) == false)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;
	for (int i = 0; i < 5; i++)
	{
		answer.push_back(Rooms(places[i]));
	}

	return answer;
}
