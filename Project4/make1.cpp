#include <iostream>
#include <algorithm>
using namespace std;
int mem[1000000];
int n;
int dfs(int k) {
	if (k == 1)return 0;
	if (mem[k])return mem[k];
	int a = 10000000, b = 10000000;
	if (k % 3==0)a = dfs(k / 3);
	if (k % 2==0)b = dfs(k / 2);
	int c = dfs(k - 1);
	return mem[k] = 1 + min(min(a, b), c);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cout << dfs(n);
	return 0;
}


