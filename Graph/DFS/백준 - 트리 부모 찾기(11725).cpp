// 백준 - 트리의 부모 찾기(11725번)
// https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
vector<vector<int>> tree;

void DFS(int node) {
	for (int i = 0; i < tree[node].size(); i++) {
		auto& next = tree[node][i];
		if (answer[next] != -1) continue; // 부모 체크 되있으면 continue

		answer[next] = node;
		DFS(next);
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	int n; cin >> n;
	tree.resize(n + 1);
	answer.resize(n + 1, -1);

	answer[1] = 1; // 루트 노드의 부모는 자기 자신

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);
	for (int i = 2; i < answer.size(); i++) cout << answer[i] << '\n';

	return 0;
}