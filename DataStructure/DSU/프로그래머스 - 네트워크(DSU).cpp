// 프로그래머스 - 네트워크(DSU)
// https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> root;
vector<int> rnk;

int Find(int x){
    if(x == root[x]) return x;
    return root[x] = Find(root[x]);
}


int solution(int n, vector<vector<int>> computers) {
    root.resize(n);
    rnk.resize(n,1);
    
    for(int i=0; i<n; i++) root[i] = i;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j || (computers[i][j] == 0)) continue;
            
            int roota = Find(i);
            int rootb = Find(j);
            
            if(roota == rootb) continue;
            
            if(rnk[roota] > rnk[rootb]){
                root[rootb] = roota;
            }
            else if(rnk[roota] < rnk[rootb]){
                root[roota] = rootb;
            }
            else{
                root[j] = roota;
                rnk[roota]++;
            }
        }    
    }
    
    int answer = 0;
    unordered_set<int> us;
    
    for(auto& r : root){
        int tr = Find(r);
        
        if(us.find(tr) == us.end()){
            us.insert(tr);
            ++answer;
        }
    }
    
    return answer;
}