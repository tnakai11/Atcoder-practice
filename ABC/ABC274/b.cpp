#include <bits/stdc++.h>
using namespace std;
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc274/tasks/abc274_b
// 愚直に数えてO(HW)
string s[1005];
void solve(){ 
    int H,W; cin >> H >> W;
    CINA(s,H);
    REP(j,W){
        int x = 0;
        REP(i,H){
            x += (s[i][j]=='#');
        }
        cout << x << (j<W-1?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}