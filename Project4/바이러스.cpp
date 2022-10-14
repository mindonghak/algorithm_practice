#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool check[101];
bool map[101][101];
int N, M;
int result;
void dfs(int n);
int main() {
	cin >> N >> M;
	int i, a,b;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(1);
	cout << result;
	return 0;
}
void dfs(int n) {
	check[n] = 1;
	result++;
	if (n == 1)result = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i])continue;
		if (!map[n][i])continue;
		dfs(i);
	}
}