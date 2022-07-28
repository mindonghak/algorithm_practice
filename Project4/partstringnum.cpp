#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set <string> M;
string temp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, j;
	string s;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		for (j = i; j < s.size(); j++) {
			temp += s[j];
			M.insert(temp);
		}
		temp = "";
	}
	cout << M.size();


	return 0;
}