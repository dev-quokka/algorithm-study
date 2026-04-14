// 프로그래머스 - 완주하지 못한 선수
// https://school.programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;
    for(auto& tp : participant) um[tp]++;
    for(auto& tc : completion) um[tc]--;
    
    for(auto iter = um.begin(); iter!=um.end(); iter++)
        if(iter->second > 0){
            answer = iter->first;
            break;
        }
    
    return answer;
}