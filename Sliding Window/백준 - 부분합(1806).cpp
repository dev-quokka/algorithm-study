// 백준 - 부분합(1806)
// https://www.acmicpc.net/problem/1806

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s; cin >> n >> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int left = 0, right = 0;
    int curTotal = 0;
    int answer = 1e9;

    while (true) {
        if (curTotal >= s) {
            answer = min(answer, right - left);
            curTotal -= v[left];
            left++;
        }
        else {
            if (right == n) break;
            curTotal += v[right];
            right++;
        }
    }

    if (answer == 1e9) cout << 0;
    else cout << answer;

    return 0;
}