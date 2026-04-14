// 프로그래머스 - 프로세스
// https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct vi{
    int val, idx;
};

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq(priorities.begin(), priorities.end()); // 우선 순위 정렬
    
    queue<vi> q;
    for(int i=0; i<priorities.size(); i++) 
        q.push({priorities[i], i});
    
    int answer = 0;
    while(!q.empty()){
        auto [val, idx] = q.front(); q.pop();
        
        if(val == pq.top()){
            pq.pop();
            ++answer;
            
            if(idx == location) return answer;
        }
        else q.push({val, idx});
    }
    
    return answer;
}