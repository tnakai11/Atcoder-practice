#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc211/tasks/abc211_a
// やるだけ
// 出力に注意
void solve(){ 
    ld A,B; cin >> A >> B;
    ld C = A/3 + B*2/3;
    cout << fixed << setprecision(6) << C << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}