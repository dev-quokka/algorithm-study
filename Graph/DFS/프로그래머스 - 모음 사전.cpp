// 프로그래머스 - 모음 사전
// https://programmers.co.kr/learn/courses/30/lessons/84512

#include <string>
#include <vector>

using namespace std;

bool fin = false;
int answer = 0;
const char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
void DFS(const string& tar, string curS){
    if(fin || curS.size() > 5) return;
    if(curS == tar){
        fin = true;
        return;
    }
    
    ++answer;
    for(int i=0; i<5; i++){
        DFS(tar, curS + alpha[i]);
        if(fin) return;
    }
}

int solution(string word) {
    string first = "";
    DFS(word, first);
    return answer;
}