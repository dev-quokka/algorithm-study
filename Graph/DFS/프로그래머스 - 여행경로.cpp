// 프로그래머스 - 여행경로
// https://school.programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> check;
vector<string> answer;

void DFS(vector<vector<string>>& tickets, string next, int ts){
    if(ts == 0 || (answer.size() == tickets.size()+1)) return;

    for(int i=0; i<tickets.size(); i++){
        if(check[i] || tickets[i][0] != next) continue;
        
        check[i] = true;
        answer.push_back(tickets[i][1]);
        DFS(tickets, tickets[i][1], ts-1);
        
        if(answer.size() == tickets.size()+1) return;
        
        answer.pop_back();
        check[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    
    int ts = tickets.size();
    check.resize(ts, false);
    answer.reserve(ts+1); // 항상 ticket 개수 + 1개가 정답 (미리 reserve로 할당해두기)
    answer.push_back("ICN");
    
    DFS(tickets, "ICN", ts);
    return answer;
}