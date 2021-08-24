#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc215/tasks/abc215_b
// 順に調べれば O(log N) でとける
// k <= log_2 N より (int) log_2 N が答え
void solve(){ 
    ld N; cin >> N;
    int ans = log2(N);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}