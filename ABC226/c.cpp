#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc226/tasks/abc226_c
// 技 N から枝を張って必要な技を探索する
// 枝数の総和を X として O(N + X) で計算可能
void solve(){ 
    int N; cin >> N;
    vector<int> tech[N+1];
    vector<ll> t(N+1);
    for(int i=1;i<=N;++i){
        int K; cin >> t[i] >> K;
        REP(k,K){
            int ak; cin >> ak;
            tech[i].emplace_back(ak);
        } 
    }

    vector<int> need(N+1,0);
    queue<int> q;
    q.push(N);
    need[N] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto y:tech[x]){
            if(need[y]) continue;
            need[y] = 1;
            q.push(y);
        }
    }

    ll ans = 0LL;
    for(int i=1;i<=N;++i){
        if(need[i]) ans += t[i];
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}