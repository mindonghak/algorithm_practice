#include <iostream>
#include <cstdlib>
using namespace std;
int n, cnt;
bool visited[15];	//���� ���� �����ִ���
int mem[15];		//i��° �࿡ mem[i]���� ���� ����
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


