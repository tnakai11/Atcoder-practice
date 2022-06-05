#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc253/tasks/abc253_b
// ２点間のマンハッタン距離を求める
// Wikipedia マンハッタン距離
// https://ja.wikipedia.org/wiki/%E3%83%9E%E3%83%B3%E3%83%8F%E3%83%83%E3%82%BF%E3%83%B3%E8%B7%9D%E9%9B%A2

struct point {
    int x,y;
};
void solve(){ 
    int H,W; cin >> H >> W;
    string board[H];
    REP(i,H) cin >> board[i];
    vector<point> v;
    REP(i,H){
        REP(j,W){
            if(board[i][j]=='o'){
                point t = {i,j};
                v.emplace_back(t);
            }
        }
    }
    point p = v[0];
    point q = v[1];
    int ans = abs(p.x-q.x) + abs(p.y-q.y);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}