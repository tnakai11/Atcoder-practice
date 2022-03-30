#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc235/tasks/abc235_c
// map でゴリ押せそう
// 構成に O(N log N)
// 検索に O(log N)
map<int,int> mp[200005]; // mp[k][x] ... x が k 回目に登場する位置
map<int,int> cnt; // x が何回登場したか数える
void solve(){ 
    int N,Q; cin >> N >> Q;
    for(int i=1;i<=N;++i){
        int x; cin >> x;
        ++cnt[x];
        int k = cnt[x];
        mp[k][x] = i;
    }
    REP(q,Q){
        int x,k; cin >> x >> k;
        int ans = mp[k][x];
        if(ans==0){
            cout << -1 << '\n';
            continue;
        }
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}