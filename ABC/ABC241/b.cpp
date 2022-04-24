#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc241/tasks/abc241_b
// パスタの本数を map で長さごとに数えておけばOK
void solve(){ 
    int N,M; cin >> N >> M;
    map<int,int> mp;
    REP(i,N){
        int a; cin >> a;
        ++mp[a];
    }
    bool ok = true;
    REP(i,M){
        int b; cin >> b;
        if(mp[b]==0){
            ok = false;
        }
        --mp[b];
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}