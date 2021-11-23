#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc225/tasks/abc225_b
// 接続する辺の数が N-1 となる節が存在する木であるかどうかを判定する
// 接続する辺の数を控えて全ての点を調べればOK
void solve(){ 
    int N; cin >> N;
    map<int,int> mp;
    REP(count,N-1){
        int a,b; cin >> a >> b;
        ++mp[a];
        ++mp[b];
    }
    bool ok = true;
    for(int i=1;i<=N;++i){
        if(mp[i]==N-1) break;
        if(mp[i]!=1){ ok = false; break;}
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}