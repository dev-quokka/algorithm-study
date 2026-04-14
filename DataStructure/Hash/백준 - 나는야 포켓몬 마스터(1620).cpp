// 백준 - 나는야 포켓몬 마스터 (1620)
// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	vector<string> v(n + 1);
	unordered_map<string, int> um;

	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		v[i] = s;
		um[s] = i;
	}

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		
        if(isdigit(s[0])){
            int num = stoi(s);
            cout << v[num] << "\n";
        }
        else cout << um[s] << "\n";
	}

	return 0;
}