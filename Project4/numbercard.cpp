#include <iostream>
#include <algorithm>
#include <string.h>
#define plus 10000000
using namespace std;
int num[20000001];
int mum[500000];


int main() {
	int n, m, i, temp;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> temp;
		num[temp+plus] = 1;
	}
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> mum[i];
		if (num[mum[i]+plus])mum[i] = 1;
		else mum[i] = 0;

	}

	for (i = 0; i < m; i++) {
		cout << mum[i] << ' ';
	}

	return 0;
}