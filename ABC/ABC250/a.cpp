#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc250/tasks/abc250_a
// 愚直に数えると O(HW)
// (R,C) の周囲4マスを調べるだけでOK
void solve(){
    int H,W; cin >> H >> W;
    int R,C; cin >> R >> C;
    int ans = 0;
    if(R+1<=H) ++ans;
    if(C+1<=W) ++ans;
    if(R-1>=1) ++ans;
    if(C-1>=1) ++ans;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}