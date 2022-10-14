#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int map[101][101];
bool check[101];
int chon[101];
int n, m;
int X, Y;
void bfs();
int main() {
	int i, x, y;
	cin >> n >> X >> Y >> m;

	for (i = 0; i < m; i++) {
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	chon[Y] = -1;
	bfs();
	printf("%d", chon[Y]);
	return 0;
}

void bfs() {
	int cur;
	queue <int> q;
	q.push(X);
	check[X] = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!map[cur][i])continue;
			if (check[i])continue;
			if (i == Y) {
				chon[Y] = chon[cur] + 1;
				return;
			}
			q.push(i);
			check[i] = 1;
			chon[i] = chon[cur] + 1;
		}
	}

}