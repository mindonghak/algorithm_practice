#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
bool map[102][102];
bool check[102][102];
short dist[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result;
void bfs();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;
	char temp;
	int ti;
	scanf("%d %d", &N, &M);
	scanf("%c", &temp);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%c", &temp);
			ti = temp == '1';
			map[i][j] = ti;
			//printf("[%d]", ti);
		}
		scanf("%c", &temp);
	}
	dist[1][1] = 1;
	bfs();

	printf("%d", dist[N][M]);
	return 0;
}
void bfs() {
	int i, j;
	int x, y;
	queue <pair<int, int>> q;

	for (i = 0; i <= M + 1; i++) {
		check[0][i] = 1;
	}
	for (i = 0; i <= M + 1; i++) {
		check[N+1][i] = 1;
	}
	for (i = 0; i <= N + 1; i++) {
		check[i][0] = 1;
	}
	for (i = 0; i <= N + 1; i++) {
		check[i][M+1] = 1;
	}
	q.push(make_pair(1, 1));
	check[1][1] = 1;
	pair <int, int> p;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (i = 0; i < 4; i++) {
			x = p.first + dx[i];
			y = p.second + dy[i];
			if (check[x][y])continue;
			if (!map[x][y])continue;
			q.push(make_pair(x, y));
			check[x][y] = 1;
			dist[x][y] = dist[p.first][p.second] + 1;
		}
		if (dist[N][M])break;
	}
}