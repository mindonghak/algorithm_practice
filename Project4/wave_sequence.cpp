#include <iostream>
#include <cstdlib>
using namespace std;
long long int mem[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	mem[1] = 1;
	mem[2] = 1;
	mem[3] = 1;
	mem[4] = 2;
	mem[5] = 2;
	int n,k;
	cin >> n;
	while (n--) {
		cin >> k;
		for (int i = 6; i <= k; i++) {
			mem[i] = (mem[i - 1] + mem[i - 5]);
		}
		cout << mem[k] << '\n';
	}
	return 0;
}


