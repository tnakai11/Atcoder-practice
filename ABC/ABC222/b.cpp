#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc222/tasks/abc222_b
// for 文を使おう
// python なら map と sum でいけそう
void solve(){ 
    int N,P; cin >> N >> P;
    int ans = 0;
    REP(i,N){
        int a; cin >> a;
        ans += a<P;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}