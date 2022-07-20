#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int desc(int a, int b) { return a > b; }
int main() {
	char c[11];
	cin >> c;
	sort(c, c + strlen(c), desc);

	cout << atoi(c);
}