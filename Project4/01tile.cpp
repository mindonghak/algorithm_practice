#include <iostream>
#include <cstdlib>
using namespace std;
int mem[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	mem[1] = 1;
	mem[2] = 2;
	int n;
	cin >> n;
	for (int i=3; i <= n; i++) {
		mem[i] = (mem[i - 1] + mem[i - 2]) % 15746;
	}
	cout << mem[n];
	return 0;
}


