#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, result = 0;
	cin >> n;
	result += n / 5;	//0의개수는 10이 몇번 곱해졌는지에 따라 정해진다.
	result += n / 25;	//10의 배수는 2와 5의 개수로 정해진다.
	result += n / 125;	//2는 항상 5의 개수보다 많다. 
	cout<< result;		//따라서 5가 몇번 곱해졌는지 세준다.
	return 0;
}
