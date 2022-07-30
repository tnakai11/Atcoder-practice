#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc261/tasks/abc261_a
// [L1,R1] と [L2,R2]の共通部分は [max(L1,L2), min(R1,R2)]
void solve(){ 
    int l[2],r[2];
    REP(i,2) cin >> l[i] >> r[i];
    int L = max(l[0],l[1]);
    int R = min(r[0],r[1]);
    int ans = max(R-L,0);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}