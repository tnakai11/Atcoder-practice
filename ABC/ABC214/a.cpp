#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc214/tasks/abc214_a
// if 文を使えばOK
void solve(){ 
    int N; cin >> N;
    int ans = 4;
    if(N>=126) ans += 2;
    if(N>=212) ans += 2;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}