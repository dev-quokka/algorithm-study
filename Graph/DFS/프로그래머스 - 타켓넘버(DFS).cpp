// 프로그래머스 - 타겟 넘버(DFS)
// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int N, answer = 0;
void DFS(vector<int>& numbers, int curVal, int cnt, int target){
    if(cnt == N){ if(curVal == target) ++answer; return;}
    DFS(numbers, curVal+numbers[cnt], cnt+1, target);
    DFS(numbers, curVal-numbers[cnt], cnt+1, target);
}

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    DFS(numbers, numbers[0], 1, target);
    DFS(numbers, -numbers[0], 1, target);
    return answer;
}