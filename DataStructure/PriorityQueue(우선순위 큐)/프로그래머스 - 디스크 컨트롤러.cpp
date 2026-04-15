// 프로그래머스 - 디스크 컨트롤러
// https://school.programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 1. 작업 큐 생성. (priority_queue)
// 2. 작업 종료 시점까지의 모든 작업을 작업 큐에 삽입
// 3. 작업 종료 후 우선 순위 가장 높은 작업 시작
// 4. 작업 종료 시간 - 작업 시작 시간의 값을 임시 변수에 더해가며
//    2~3번 작업 반복
// 5. 임시 변수 / 작업 수 반환

struct JobTime {
	int req, used;

	bool operator<(const JobTime& other) const {
		if (used != other.used) return used > other.used;
		if (req != other.req) return req > other.req;
	}
};

int solution(vector<vector<int>> jobs) {
	// 시작 시간 기준 정렬
	sort(jobs.begin(), jobs.end(), [](const vector<int>& v1, const vector<int>& v2) {
		return v1[0] < v2[0];
		});

	priority_queue<JobTime> pq;

	int answer = 0;
	int idx = 0;
	int endTime = 0;

	while (idx < jobs.size()) {
		while (idx < jobs.size() && jobs[idx][0] <= endTime) {
			pq.push({ jobs[idx][0], jobs[idx][1] });
			idx++;
		}

		if (pq.empty()){
            endTime = jobs[idx][0];
            continue;
        }

		auto [req, used] = pq.top(); pq.pop();
		endTime += used;

		answer += (endTime - req);
	}

	while (!pq.empty()) {
		auto [req, used] = pq.top(); pq.pop();
		endTime += used;

		answer += (endTime - req);
	}

	answer /= jobs.size();
	return answer;
}