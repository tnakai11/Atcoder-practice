#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
#define ll long long
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc224/tasks/abc224_b
// 全探索で O( H^2 W^2)
// この問題では間に合う
void solve(){ 
    int H,W; cin >> H >> W;
    ll a[H][W]; 
    REP(h,H) REP(w,W) cin >> a[h][w];
    bool ok = true;
    REP(h1,H) REP(h2,H){
        if(h1>=h2) continue;
        REP(w1,W) REP(w2,W){
            if(w1>=w2) continue;
            ll x = a[h1][w1] + a[h2][w2];
            ll y = a[h2][w1] + a[h1][w2];
            if(x>y){ ok = false; break; }
        }
        if(!ok) break;
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}