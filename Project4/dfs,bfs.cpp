#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int node[1001][1001];
int spot[1001];
int qspot[1001];
int N, M, V;
void dfs(int k);
void bfs();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	int temp[2];
	cin >> N >> M >> V;
	for (i = 0; i < M; i++) {
		cin >> temp[0] >> temp[1];
		node[temp[0]][temp[1]] = 1;
		node[temp[1]][temp[0]] = 1;
	}
	dfs(V);
	printf("\n");
	bfs();


	return 0;
}


void dfs(int k) {
	if (spot[k])return;
	int i;
	spot[k] = 1;
	printf("%d ",k);
	for (i = 1; i <= N; i++) {
		if (!node[i][k])continue;
		dfs(i);
	}
}

void bfs() {
	queue <int> q;
	q.push(V);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		if (qspot[k])continue;
		printf("%d ", k);
		for (int i = 1; i <= N; i++) {
			if (!node[i][k])continue;
			q.push(i);
		}
		qspot[k] = 1;
	}
}