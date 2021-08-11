#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc213/tasks/abc213_d
// 深さ優先探索
vector<int> neigh[200005];
int vst[200005];
vector<int> ans;
void dfs(int cur){
    vst[cur] = 1;
    ans.emplace_back(cur);
    for(int nxt: neigh[cur]){
        if(vst[nxt]) continue;
        dfs(nxt);
        ans.emplace_back(cur);
    }
}
void solve(){ 
    int N; cin >> N;
    REP(i,N-1){
        int a,b; cin >> a >> b;
        neigh[a].emplace_back(b);
        neigh[b].emplace_back(a);
    }
    REP(x,N+1){
        sort(ALL(neigh[x]));
    }
    dfs(1);
    int M = ans.size();
    REP(i,M){
        cout << ans[i] << (i==M-1?'\n':' ');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}