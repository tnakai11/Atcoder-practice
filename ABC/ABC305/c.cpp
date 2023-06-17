#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
// https://atcoder.jp/contests/abc305/tasks/abc305_c
// a,b,c,dを構成しきってから内部を全探索. O(HW)
void solve(){ 
    int H,W; cin >> H >> W;
    string s[H];
    REP(h,H) cin >> s[h];
    int h_min=H,h_max=0;
    int w_min=W,w_max=0;
    REP(h,H) {
        REP(w,W) {
            if(s[h][w]=='#'){
                chmin(h_min,h);
                chmin(w_min,w);
                chmax(h_max,h);
                chmax(w_max,w);
            }
        }
    }
    for(int h=h_min;h<=h_max;++h){
        for(int w=w_min;w<=w_max;++w){
            if(s[h][w]=='.'){
                cout << h+1 << ' ' << w+1 << '\n';
            }
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}