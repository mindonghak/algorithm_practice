#include <iostream>
using namespace std;
#define text1 "\"����Լ��� ������?\"\n"
#define text2 "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"
#define text3 "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n"
#define text4 "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n"
#define last_text1 "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n"
#define last_text2 "��� �亯�Ͽ���.\n"
#define re_text "____"
void re_text_repeat(int n);
void recursion(int n, int k);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recursion(n,0);



	return 0;
}

void re_text_repeat(int n) {
	int i;
	for (i = 0; i < n; i++) {
		cout << re_text;
	}
}

void recursion(int n, int k) {
	re_text_repeat(k);
	cout << text1;
	if (!n) {
		re_text_repeat(k);
		cout << last_text1;
		re_text_repeat(k);
		cout << last_text2;
		return;
	}
	re_text_repeat(k);
	cout << text2;
	re_text_repeat(k);
	cout << text3;
	re_text_repeat(k);
	cout << text4;
	recursion(n-1, k+1);
	re_text_repeat(k);
	cout << last_text2;
}