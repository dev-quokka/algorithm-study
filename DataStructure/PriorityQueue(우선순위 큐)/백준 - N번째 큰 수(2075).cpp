// 백준 - N번째 큰 수(2075)
// https://www.acmicpc.net/problem/2075

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n; cin >> n;

	// 최소힙
	priority_queue<int, vector<int>, greater<>> pq;
    
    int num; 
	for (int i = 0; i < n * n; i++) {
		cin >> num;
		if (pq.empty() || pq.size() < n) pq.push(num);
        else if (pq.top() < num) {
            pq.pop();
            pq.push(num);
        }
	}

	cout << pq.top();
	return 0;
}