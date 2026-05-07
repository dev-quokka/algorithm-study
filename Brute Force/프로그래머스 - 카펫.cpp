// 프로그래머스 - 카펫
// https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int b, int y) {    
    int total = b+y;
    int hei = 0;
    
    while(++hei <= y){
        if(y % hei != 0) continue;
        int wid = y / hei;
        
        int tempTotal = (wid + 2) * (hei + 2);
        if(tempTotal == total) return {wid+2, hei+2};
    }
}