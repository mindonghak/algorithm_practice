#include <iostream>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
set<string> N;
string M[10000];

int Count;
int main() {
	int n, m, i,j;
	string temp;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++) {
		cin >> temp;
		N.insert(temp);
	}
	for (i = 0; i < m; i++) {
		cin >> M[i];
	}
	for (i = 0; i < m; i++) {
		if (N.end() != N.find(M[i])) {
			Count++;
		}
	}
	cout << Count;
	return 0;
}