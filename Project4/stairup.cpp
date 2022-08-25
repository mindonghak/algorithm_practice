#include <iostream>
#include <algorithm>
using namespace std;
int stair[305];
int mem[305];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, i, temp[2];
	cin >> n;
	for (i = 3; i < n+3; i++) {
		cin >> stair[i];
		temp[0] = mem[i - 2] == 0 ? stair[i - 2] : mem[i - 2];
		temp[1] = mem[i - 3] == 0 ? stair[i - 3] + stair[i - 1] : mem[i - 3] + stair[i - 1];
		mem[i] = stair[i] + max(temp[0], temp[1]);
	}
	cout << mem[n + 2];
	return 0;
}


