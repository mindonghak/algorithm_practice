#include <iostream>
using namespace std;

int fact(int n);

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << fact(n);
	return 0;
}

int fact(int n) {
	if (n==0||n==1)return 1;
	return n * fact(n - 1);
}

