#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc244/tasks/abc244_b
// 愚直にシミュレートしても O(N) で済む
// 記述量を減らす工夫があるとバグがすくなそう
// ベクトルの回転をやる
struct position {
    int x,y;
};
struct muki {
    int dx,dy;
};
position goStraight(position p, muki m){
    p.x += m.dx;
    p.y += m.dy;
    return p;
}
muki turnRight(muki m){
    muki n;
    n.dx = m.dy;
    n.dy = -m.dx;
    return n;
}
void solve(){ 
    int N; cin >> N;
    string s; cin >> s;
    position p = {0,0};
    muki m = {1,0};
    for(char c: s){
        if(c=='S'){
            p = goStraight(p,m);
        }else{
            m = turnRight(m);
        }
    }
    cout << p.x << ' ' << p.y << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}