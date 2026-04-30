// 프로그래머스 - [1차] 다트게임
// https://programmers.co.kr/learn/courses/30/lessons/17682

// 벡터 풀이
#include <string>
#include <vector>
#include <cmath>

using namespace std;

 int CalScore(string& ts, char tr){
     int ti = stoi(ts);
    
     if(tr == 'S') return ti;
     else if(tr == 'D') return ti * ti;
     else if(tr == 'T') return ti * ti * ti;
 }

int solution(string dartResult) {
    vector<int> v;
    string ts = "";
    for(auto& tr : dartResult){
        if(tr == 'D' || tr == 'S' || tr == 'T'){
             v.push_back(CalScore(ts, tr));
             ts = "";
         }
         else{
            if(tr == '*'){
                if(v.size()>=2){
                    v[v.size()-1] *= 2;
                    v[v.size()-2] *= 2;
                }
                else v[v.size()-1] *= 2;
            }
            else if(tr == '#'){
                v[v.size()-1] *= -1;
            }
            else ts += tr;
        }
    }
    
    int answer = 0;
    for(auto& ti : v) answer += ti;
    
    return answer;
}

// 스택 풀이 연습용 (타임 비교용)
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int CalScore(string& ts, char tr){
    int ti = stoi(ts);
    
    if(tr == 'S') return pow(ti, 1);
    else if(tr == 'D') return pow(ti, 2);
    else if(tr == 'T') return pow(ti, 3);
}

int solution(string dartResult) {
    stack<int> s;
    string ts = "";
    for(auto& tr : dartResult){
        if(tr == 'D' || tr == 'S' || tr == 'T'){
            s.push(CalScore(ts, tr));
            ts = "";
        }
        else{
            if(tr == '*'){
                int temp1 = -1;
                int temp2 = -1;
                
                for(int i=0; i<2; i++){
                    if(s.empty()) break;
                    
                    int tsv = s.top(); s.pop();
                    if(temp1 == -1){
                        temp1 = 0;
                        temp1 += (tsv * 2);
                    }
                    else{
                        temp2 = 0;
                        temp2 += (tsv * 2);
                    }
                }

                if(temp2 == -1) s.push(temp1);
                else{
                    s.push(temp2);
                    s.push(temp1);
                }
            }
            else if(tr == '#'){
                int tsv = s.top(); s.pop();
                s.push(-tsv);
            }
            else ts += tr;
        }
    }
    
    int answer = 0;
    while(!s.empty()){
        int st = s.top(); s.pop();
        answer += st;
    }
    
    return answer;
}