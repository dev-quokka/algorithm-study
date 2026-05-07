// 프로그래머스 - 올바른 괄호
// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> sc;
    bool answer = true;
    
    for(auto& c : s){
        if(!sc.empty() && sc.top() == '(' && c == ')') sc.pop();
        else sc.push(c);
    }
    
    if(!sc.empty()) answer = false;
    return answer;
}