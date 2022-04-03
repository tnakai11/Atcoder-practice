#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc237/tasks/abc237_b
// 素直に出力すればOK
// メモリを節約しなかったためCE
// 1次元配列でがんばる
int a[100005];
void solve(){ 
    int H,W; cin >> H >> W;
    REP(h,H){
        REP(w,W){
            cin >> a[h*W + w];
        }
    }
    REP(w,W){
        REP(h,H){
            cout << a[h*W + w];
            cout << (h<H-1?' ':'\n');
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}