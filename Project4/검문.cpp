#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int a[1001][1001];
int f(int x, int y);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, x, y;
	cin >> x >> y;
	
	cout << f(x,y);
	return 0;
}

int f(int x, int y) {
	if (a[x][y])return a[x][y];
	if (y == 0 || x == y)return 1;
	if (y == 1)return x;
	a[x][y] = f(x - 1, y - 1) + f(x - 1, y);
	return a[x][y] % 10007;
}