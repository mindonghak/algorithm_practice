#include <iostream>
#define pi 3.14159265359

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r * r * pi << '\n' << (double)r * r * 2;

	return 0;
}