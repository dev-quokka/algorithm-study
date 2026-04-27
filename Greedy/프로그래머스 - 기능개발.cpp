// 프로그래머스 - 기능개발
// https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>

using namespace std;

int CalWorkTime(int pt, int st) {
    int remainTime = 100 - pt;
    return (remainTime + st - 1) / st;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int cur = CalWorkTime(progresses[0], speeds[0]);
    int cnt = 1;

    for (int i = 1; i < progresses.size(); i++) {
        int workTime = CalWorkTime(progresses[i], speeds[i]);

        if (workTime <= cur) {
            cnt++;
        } else {
            answer.push_back(cnt);
            cur = workTime;
            cnt = 1;
        }
    }

    answer.push_back(cnt);
    return answer;
}