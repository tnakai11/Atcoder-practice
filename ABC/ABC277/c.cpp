#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
// https://atcoder.jp/contests/abc277/tasks/abc277_c
// BFSで1階につながる最上階を探す
// 計算量はO(N)
void solve(){ 
    int N; cin >> N;
    map<int, vector<int>> mp;
    REP(i,N){
        int a,b; cin >> a >> b;
        mp[a].emplace_back(b);
        mp[b].emplace_back(a);
    }
    int ans = 0;
    queue<int> q;
    map<int,int> vs;
    q.push(1);
    vs[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        chmax(ans,x);
        for(int next:mp[x]){
            if(vs[next]==1) continue;
            vs[next] = 1;
            q.push(next);
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}