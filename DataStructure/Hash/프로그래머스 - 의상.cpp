// 프로그래머스 - 의상
// https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for(auto& t : clothes) 
        m[t[1]]++;
    
    int answer = 1;
    for(auto& ts : m) 
        answer *= (ts.second + 1);
        
    return answer-1;
}