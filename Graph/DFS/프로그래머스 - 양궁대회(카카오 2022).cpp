// 프로그래머스 - 양궁대회
// https://school.programmers.co.kr/learn/courses/30/lessons/92342

// 점수 차 인지 모르고, 최고 점수로 풀다가 2시간 걸렸던 문제..
// 문제를 잘 읽고 함정에 빠지지 말자

#include <string>
#include <vector>

using namespace std;

bool check = false;
int curMaxDif = 0; // 점수 차이 최대값

vector<int> temp;
vector<int> answer;
void CompareAnswer(int tempDif){
    check = true;
    
    if(tempDif > curMaxDif){ // 무조건 갱신
        curMaxDif = tempDif;
        answer = temp;
    }
    else{
        for(int i=10; i>=0; i--){
            if(temp[i] == answer[i]) continue;
            if(temp[i] > answer[i]){
                curMaxDif = tempDif;
                answer = temp;  
            }
            else break;
        }    
    }
    return;
}

void dfs(const vector<int>& info, int pitchScore, int myScore, int curIdx, int n){
    if(curIdx == 11){
        if(n!=0 || (pitchScore >= myScore)) return; // 화살 다 못쐈거나 피치보다 점수 낮으면 돌아가기
        
        int tempDif = myScore - pitchScore;
        if(tempDif < curMaxDif) return; // 점수차 같거나 더 크면 비교 시작
        
        CompareAnswer(tempDif);
        return;
    }
    
    for(int i=0; i<=n; i++){    
        temp[curIdx] = i;
        
        if(i <= info[curIdx]){ // 피치가 더 많이 쏨
            if(info[curIdx] == 0) dfs(info, pitchScore, myScore, curIdx+1, n-i); // 둘 다 0일떄
            else dfs(info, pitchScore + 10 - curIdx, myScore, curIdx+1, n-i);
            
        }
        else{ // 내가 더 많이 쏨
            dfs(info, pitchScore, myScore + 10 - curIdx, curIdx+1, n-i);   
        }
        
        temp[curIdx] = 0; 
    }
}

vector<int> solution(int n, vector<int> info) {
    temp.resize(11, 0);
    answer.resize(11, 0);
    
    dfs(info, 0, 0, 0, n);
    
    if(!check) return {-1};
    return answer;
}