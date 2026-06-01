// 프로그래머스 - 두 개 뽑아서 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/68644

#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

// set, unordered_set 두 가지 풀이로 진행
// unordered_set이 더 빠를 것으로 예상
// - set: 삽입마다 O(log n) 트리 탐색
// - unordered_set: 평균 O(1) 삽입 + 마지막 정렬 1회

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    // 1. set 풀이
    set<int> s;
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer.reserve(s.size());
    for(auto& ts : s) answer.push_back(ts);
    
    
    // 2. unordered_set 풀이
    unordered_set<int> us;
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            us.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer.reserve(us.size());
    for(auto& tus : us) answer.push_back(tus);
    
    sort(answer.begin(), answer.end());
    return answer;
}