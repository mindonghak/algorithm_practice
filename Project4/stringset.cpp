#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map <string, int> M;
string M2[100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, i;
	string temp;
	cin >> n;
	cin >> m;
	for (i = 0; i < n; i++) {
		cin >> temp;
		M.insert({ temp,i });
		M2[i] = temp;
	}
	for (i = 0; i < m; i++) {
		cin >> temp;
		if (isdigit(temp[0])) {
			cout << M2[stoi(temp)-1]<<'\n';
		}
		else {
			cout << M.find(temp)->second+1<<'\n';
		}
	}

	return 0;
}