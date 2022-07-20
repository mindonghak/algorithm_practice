#include <iostream>
#define positive 4000
using namespace std;
int memo[8002];
int Sum;
int main() {
	int n, i,temp,min_mode=0;
	int mean, median, mode, Min = 8002, Max = -1;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> temp;
		temp += positive;
		if (temp < Min)Min = temp;
		if (temp > Max)Max = temp;
		Sum += temp-positive;
		memo[temp]++;
	}
	if(Sum>0)mean = (Sum + (n - 1) / 2) / n;
	else mean = (Sum - (n - 1) / 2) / n;
	temp = n;
	for (i = Min; i <= Max; i++) {
		if (!memo[i])continue;
		temp -= memo[i];
		if (temp < (n + 1) / 2) {
			median = i-positive;
			break;
		}
	}
	temp = 0;
	for (i = Min; i <= Max; i++) {
		if (!memo[i])continue;
		if (memo[i] > temp) {
			temp = memo[i];
			mode = i - positive;
			min_mode = 1;
		}
		else if (memo[i] == temp) {
			if (min_mode==1) {
				min_mode = 2;
				mode = i - positive;
			}
		}
		
	}
	cout << mean << '\n' << median << '\n' << mode << '\n' << Max - Min;

	return 0;
}