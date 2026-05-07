// 프로그래머스 - 짝지어 제거하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12973

#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string ss)
{
    stack<char> s;
    int answer = 1;
    for(auto& ts : ss){
        if(s.empty() || s.top() != ts) s.push(ts);
        else s.pop();
    }
    if(!s.empty()) answer = 0;
    return answer;
}