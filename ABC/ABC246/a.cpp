#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc246/tasks/abc246_a
// 長方形がx軸,y軸に平行であることから
// x 軸に関しては x0=x1,x0=x2,x0=x3 の 3パターン
// y 軸も同様
void solve(){ 
    int x[3],y[3];
    REP(i,3) cin >> x[i] >> y[i];

    int ansX = x[0];
    if(x[0]==x[1]) ansX = x[2];
    if(x[0]==x[2]) ansX = x[1];
    int ansY = y[0];
    if(y[0]==y[1]) ansY = y[2];
    if(y[0]==y[2]) ansY = y[1];

    cout << ansX << ' ' << ansY << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}