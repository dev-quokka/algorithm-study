// 프로그래머스 - 행렬 테두리 회전하기
// https://programmers.co.kr/learn/courses/30/lessons/77485

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<vector<int>> m; // 시작 원본

void Rot(int y1, int x1, int y2, int x2){
    int temp = m[y1][x1];
    int curMin = temp;
    
    // left
    for(int i=y1; i<y2; i++){
        m[i][x1] = m[i+1][x1];
        curMin = min(curMin, m[i][x1]);
    }
    
    // down
    for(int i=x1; i<x2; i++){
        m[y2][i] = m[y2][i+1];
        curMin = min(curMin, m[y2][i]);
    }
    
    // right
    for(int i=y2; i>y1; i--){
        m[i][x2] = m[i-1][x2];
        curMin = min(curMin, m[i][x2]);
    }
    
    // up
    for(int i=x2; i>x1+1; i--){
        m[y1][i] = m[y1][i-1];
        curMin = min(curMin, m[y1][i]);
    }
    
    m[y1][x1+1] = temp;
    answer.push_back(curMin);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    answer.reserve(queries.size());
    m.resize(rows, vector<int>(columns, 0));
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            m[i][j] = (i*columns) + j + 1;
        }
    }
    
    for(auto& tq : queries)
        Rot(tq[0]-1, tq[1]-1, tq[2]-1, tq[3]-1);
    
    return answer;
}