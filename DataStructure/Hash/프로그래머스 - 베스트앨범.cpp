// 프로그래머스 - 베스트앨범
// https://school.programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct PlayTotalTime{
    int t; // 플레이 횟수
    string g; // 장르
};

struct PlayTime{
    int t, num; // 플레이 횟수, 고유번호
};

// 각 장르별 재생 횟수 체크 (장르, 재생 횟수 total)
// 장르 내부 재생 횟수 높은 순 2개
// 재생 횟수 같으면 고유 번호 순

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    vector<PlayTotalTime> pv;
    unordered_map<string, int> total_um;
    unordered_map<string, vector<PlayTime>> p_um;
    
    for(int i=0; i<genres.size(); i++){
        total_um[genres[i]] += plays[i];      
        p_um[genres[i]].push_back({plays[i], i});
    }
    
    for(auto& [g, t] : total_um){
        pv.push_back({t, g});
    }
    
    sort(pv.begin(), pv.end(), [](const PlayTotalTime& a, const PlayTotalTime& b){
        return a.t > b.t;
    });
    
    for(auto& [t, g] : pv){
        auto& v = p_um[g]; // v = vector<PlayTime>
        
        sort(v.begin(), v.end(), [](const PlayTime& a, const PlayTime& b){
            if(a.t == b.t) return a.num < b.num;
            return a.t > b.t;
        });
        
        int tempIdx = min(2, (int)v.size());
        for(int i=0; i<tempIdx; i++) answer.push_back(v[i].num);
    }
    
    return answer;
}