#include <iostream>
using namespace std;
#define text1 "\"재귀함수가 뭔가요?\"\n"
#define text2 "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n"
#define text3 "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n"
#define text4 "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n"
#define last_text1 "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n"
#define last_text2 "라고 답변하였지.\n"
#define re_text "____"
void re_text_repeat(int n);
void recursion(int n, int k);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
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