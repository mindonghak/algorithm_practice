#include <iostream>
#include <cstdlib>
using namespace std;
int count1, count2;
int mem[41];

int fibo1(int n) {
	if (n == 1 || n == 2) {
		count1++;
		return 1;
	}
	return fibo1(n - 1) + fibo1(n - 2);
}
int fibo2(int n) {
	mem[1] = mem[2] = 1;
	int i;
	for (i = 3; i <= n; i++) {
		mem[i] = mem[i - 1] + mem[i - 2];
		count2++;
	}
	return mem[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	fibo1(n);
	fibo2(n);

	cout << count1 << ' ' << count2;

	return 0;
}


