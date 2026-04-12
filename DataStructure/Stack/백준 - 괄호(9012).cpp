#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool Check(string pa) {
	stack<char> s;

	for (auto& tpa : pa) {
		if (s.empty()) {
			s.push(tpa);
			continue;
		}

		if (s.top() == tpa) s.push(tpa);
		else {
			if (s.top() == '(') {
				s.pop();
			}
			else s.push(tpa);
		}
	}

	if (s.empty()) return true;
	else return false;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string ts; cin >> ts;
		if (Check(ts)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}