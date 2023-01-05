#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000
using namespace std;

vector <pair<int, int>> a[1001], b[1001];
priority_queue <pair<int, int>> pq;
int N, M, X;

int dijkstra(int start);
int main() {
	cin >> N >> M >> X;
	int temp[3];
	for (int i = 1; i <= M; i++) {
		cin >> temp[0] >> temp[1] >> temp[2];
		a[temp[0]].push_back(make_pair(temp[1], temp[2]));
		b[temp[1]].push_back(make_pair(temp[0], temp[2]));
	}
	cout << dijkstra(X);
	return 0;
}


int dijkstra(int start) {
	vector <int> d(N+1, INF);
	d[0] = 0;
	d[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		int cur_i = pq.top().first;
		int cur_d = -pq.top().second;
		pq.pop();
		for (int i = 0; i < a[cur_i].size(); i++) {
			//cout << i;
			int next_i = a[cur_i][i].first;
			int next_d = cur_d + a[cur_i][i].second;
			if (next_d < d[next_i]) {
				d[next_i] = next_d;
				pq.push({ next_i,-next_d });
			}
			//cout << 't';
		}
	}

	vector <int> dd(N + 1, INF);
	dd[0] = 0;
	dd[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		int cur_i = pq.top().first;
		int cur_d = -pq.top().second;
		pq.pop();
		for (int i = 0; i < b[cur_i].size(); i++) {
			//cout << i;
			int next_i = b[cur_i][i].first;
			int next_d = cur_d + b[cur_i][i].second;
			if (next_d < dd[next_i]) {
				dd[next_i] = next_d;
				pq.push({ next_i,-next_d });
			}
			//cout << 't';
		}
	}
	for (int i = 1; i <= N; i++) {
		d[i] += dd[i];
	}

	return *max_element(d.begin(), d.end());
}