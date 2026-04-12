// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;

bool check[200] = {false};
void DFS(vector<vector<int>>& computers, int curIdx){
    for(int i=0; i<computers[curIdx].size(); i++){
        if(check[i] || computers[curIdx][i] == 0) continue;
        check[i] = true;
        DFS(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(check[i]) continue;
        check[i] = true;
        DFS(computers, i);
        ++answer;
    }

    return answer;
}