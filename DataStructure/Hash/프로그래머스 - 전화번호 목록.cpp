// 프로그래머스 - 전화번호 목록
// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 1. unordered_set 풀이
bool solution(vector<string> phone_book) {
    unordered_set<string> us;
    for(auto& p : phone_book) us.insert(p);
    
    for(auto& p : phone_book){
        string temp = "";
        for(auto& tp : p){
            temp += tp;
            if((us.find(temp) != us.end()) && p != temp)
                return false;
        }
    }   

    return true;
}

// 2. 정렬 풀이
bool WordCheck(const string& a, const string& b){
    if(b.substr(0, a.size()) == a) return true;
    return false;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    bool answer = true;
    for(int i=1; i<phone_book.size(); i++){
        if(WordCheck(phone_book[i-1], phone_book[i])) return false;
    }
    
    return answer;
}