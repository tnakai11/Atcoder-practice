#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc209/tasks/abc209_a
// A<=B が成り立つなら差 + 1 が答え
// A > B に注意
void solve(){ 
    int A,B; cin >> A >> B;
    int ans = 0;
    if(A<=B){
        ans = B - A + 1;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}