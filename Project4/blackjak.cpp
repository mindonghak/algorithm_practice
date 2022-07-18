#include <iostream>
#include <algorithm>
using namespace std;

int card[100];
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, m;
	int i,j,k;
	int max=0, temp;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			for (k = j+1; k < n; k++) {
				temp = card[i] + card[j] + card[k];
				if (temp > m)break;
				if (temp > max)max = temp;
			}
		}
	}
	cout << max;
	return 0;
}