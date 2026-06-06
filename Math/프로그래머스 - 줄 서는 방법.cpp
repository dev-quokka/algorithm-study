// 프로그래머스 - 줄 서는 방법
// https://school.programmers.co.kr/learn/courses/30/lessons/12936

#include <string>
#include <vector>

using namespace std;

// 완전탐색 - DFS (시간 초과)
// 완전탐색으로 진행하여 k번째 일 때 종료
long long cur = 0;
bool fin = false;
bool check[21] = {false}; // 0번 인덱스는 안씀
vector<int> temp;
vector<int> answer;

void DFS(long long k, int n, int idx){
    if(fin) return;
    
    if(idx == n){
        if(++cur == k){
            fin = true;
            answer = temp;
            return;
        }
    }
    
    for(int i=1; i<=n; i++){
        if(fin) return;
        if(check[i]) continue;
        check[i] = true;
        temp[idx] = i;
        DFS(k, n, idx+1);
        check[i] = false;
    }
}

vector<int> solution(int n, long long k) {
    temp.resize(n);
    answer.resize(n);
    DFS(k, n, 0);
    return answer;
}

// 순열 풀이
// 팩토리얼을 나눠가며 해당 인덱스에 들어갈 숫자 찾고 지우기
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;
    vector<long long> fact(n + 1, 1);

    answer.reserve(n);

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact[i] = fact[i - 1] * i;
    }

    k--;

    for (int i = n; i >= 1; i--) {
        long long blockSize = fact[i - 1];
        int index = k / blockSize;

        answer.push_back(nums[index]);
        nums.erase(nums.begin() + index);

        k %= blockSize;
    }

    return answer;
}