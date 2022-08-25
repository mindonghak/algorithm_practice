#include <iostream>
#include <algorithm>
using namespace std;
int num[200000];
int mem[200000];
int n;
int dfs(int depth, int k) {
	if (mem[k])return mem[k];
	if (n == depth)return mem[k] = num[k];

	return mem[k] = num[k] + max(dfs(depth + 1, k + depth), dfs(depth + 1, k + depth + 1));

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int i,temp = (n*(n+1))/2;
	for (i = 0; i < temp; i++) {
		cin >> num[i];
	}
	dfs(1, 0);
	cout << mem[0];

	return 0;
}


