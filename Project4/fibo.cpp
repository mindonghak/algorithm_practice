#include <iostream>

using namespace std;

int fibo(int n);
int memo[20];
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	memo[1] = 1;
	cin >> n;
	cout << fibo(n);
	return 0;
}

int fibo(int n) {
	if (n == 1 || n == 0)return n;
	if (memo[n])return memo[n];
	return memo[n] = fibo(n - 1) + fibo(n - 2);
}