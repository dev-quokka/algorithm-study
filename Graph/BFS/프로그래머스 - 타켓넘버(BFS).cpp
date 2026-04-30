// 프로그래머스 - 타겟 넘버
// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <queue>

using namespace std;
    
int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    q.push(numbers[0]); q.push(-numbers[0]);
    
    int cnt = 1;
    while(cnt < numbers.size()){
        int qsize = q.size();
        while(qsize--){
            int qfront = q.front(); q.pop();
            q.push(qfront + numbers[cnt]); q.push(qfront - numbers[cnt]);
        }
        ++cnt;
    }
    
    while(!q.empty()){
        int qfront = q.front(); q.pop();
        if(qfront == target) ++answer;
    }
    
    return answer;
}