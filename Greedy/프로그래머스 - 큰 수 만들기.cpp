// 프로그래머스 - 큰 수 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(string number, int k) {
    deque<char> d;
    for(auto& c : number){
        while(!d.empty() && d.back() < c && k > 0){
            d.pop_back();
            --k;
        }
        
        d.push_back(c);
    }
    
    while(k > 0){
        d.pop_back();
        --k;
    }
    
    string answer = "";
    answer.reserve(d.size());
    for(auto& c : d) answer.push_back(c);
    
    return answer;
}