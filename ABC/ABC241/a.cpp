#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc241/tasks/abc241_a
// map か 配列でマッピングすればOK
void solve(){ 
    int N = 10;
    int a[N];
    REP(i,N){
        cin >> a[i];
    }
    int ans = 0;
    REP(count,3){
        ans = a[ans];
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}