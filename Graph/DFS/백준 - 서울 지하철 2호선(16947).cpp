// 백준 - 서울 지하철 2호선(16947)
// https://www.acmicpc.net/problem/16947

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> answer;
vector<bool> check;
vector<vector<int>> station;
queue<int> q;
stack<int> s;

void DFS(int prev, int next){
    if(!q.empty()) return; // 이미 사이클이 발견된 경우 return
    
    check[next] = true;
    s.push(next);

    for(int i = 0; i < station[next].size(); i++){
        if(station[next][i] == prev) continue;

        int nexts = station[next][i];
        if(check[nexts]){
            while(!s.empty()){
                int top = s.top(); s.pop();
                
                q.push(top);
                answer[top] = 0;

                if(top == nexts) return;
            }
        } 

        DFS(next, nexts);
        if(!q.empty()) return;
    }

    s.pop();
    return;
}


int main(){
    int n;
    cin >> n;

    check.resize(n + 1);
    station.resize(n + 1);
    answer.resize(n + 1, -1);
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        station[a].push_back(b);
        station[b].push_back(a);
    }

    DFS(0, 1);

    int cnt = 1;
    while(!q.empty()){
        int qSize = q.size();

		for (int j = 0; j < qSize; j++) {
            int front = q.front(); q.pop();

            for(int i = 0; i < station[front].size(); i++){
                int next = station[front][i];
                if(answer[next] == -1){
                    answer[next] = cnt;
                    q.push(next);
                }
            }
        }

        ++cnt;
    }
    
    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }
    
    return 0;
}