#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int n, m, result = 0,result2=0, i;
	cin >> n >> m;
	for (i = 5; i <= n; i *= 5) {	//n까지에 5가 몇번 곱해졌는지
		result += n / i;
	}
	for (i = 5; i <= n - m; i *= 5) {	//n-m까지 5가 몇번 곱해졌는지
		result -= (n - m) / i;
	}
	for (i = 5; i <= m; i *= 5) {	//m까지 5가 몇번 곱해져 있는지
		result -= m / i;
	}
	for (i = 2; i <= n; i *= 2) {	//n까지에 2가 몇번 곱해졌는지
		result2 += n / i;
	}
	for (i = 2; i <= n - m; i *= 2) {	//n-m까지 2가 몇번 곱해졌는지
		result2 -= (n - m) / i;
	}
	for (i = 2; i <= m; i *= 2) {	//m까지 2가 몇번 곱해져 있는지
		result2 -= m / i;
	}
	cout << min(result, result2);		//따라서 2와 5중 더 작은 것이 몇번 곱해졌는지 세준다.
	return 0;
}
