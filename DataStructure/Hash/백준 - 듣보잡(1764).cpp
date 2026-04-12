// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(){
    int n,m; cin >> n >> m;
    
    unordered_set<string> us;
    for(int i=0; i<n; i++){
        string t; cin >> t;
        us.insert(t);
    }
    
    vector<string> ans;
    for(int i=0; i<m; i++){
        string t; cin >> t;
        if(us.find(t) != us.end()) ans.push_back(t);
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for(auto& na : ans) cout << na << '\n';
    
    return 0;
}