#include <iostream>
#include <cstdlib>
using namespace std;
int n, cnt;
bool visited[15];	//열에 퀸이 놓여있는지
int mem[15];		//i번째 행에 mem[i]열에 퀸이 있음
int check(int depth) {
	for (int j = 1; j < depth; j++) {
		if (depth - j == abs(mem[depth] - mem[j]))return 1;
	}
	return 0;
}
void dfs(int depth) {
	if (depth == n+1) {
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		mem[depth] = i;
		if (check(depth))continue;
		visited[i] = true;
		dfs(depth + 1);
		visited[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	dfs(1);
	cout << cnt;
	return 0;
}


