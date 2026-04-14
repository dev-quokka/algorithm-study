// 백준 - 트리 순회(1991)
// https://www.acmicpc.net/problem/1991

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> tree;

// 전위 순회
void Pre(char cur) {
	if (cur == '.') return;
	cout << cur;
	
	auto v = tree[cur - 'A'];

	if (v[0] != '.') Pre(v[0]);
	if (v[1] != '.') Pre(v[1]);
}

// 중위 순회
void In(char cur) {
	if (cur == '.') return;

	auto v = tree[cur - 'A'];

	if (v[0] != '.') In(v[0]);
	cout << cur;
	if (v[1] != '.') In(v[1]);
}

// 후위 순회
void Post(char cur) {
	if (cur == '.') return;

	auto v = tree[cur - 'A'];

	if (v[0] != '.') Post(v[0]);
	if (v[1] != '.') Post(v[1]);
	cout << cur;
}


int main() {
	int n; cin >> n;

	tree.resize(n, vector<char>(2));
	for (int i = 0; i < n; i++) {
		char root, left, right; 
		cin >> root >> left >> right;
		
		tree[root - 'A'][0] = left;
		tree[root - 'A'][1] = right;
	}

	Pre('A'); cout << '\n';
	In('A'); cout << '\n';
	Post('A');

	return 0;
}