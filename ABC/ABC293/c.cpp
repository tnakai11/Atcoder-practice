#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc293/tasks/abc293_c
// テストケースより高々５万経路未満なので全探索でいけそう 
int H,W; 
int ans = 0;
int a[15][15];
void func(int h,int w, set<int> s){
    if(h==H || w==W) return;
    int value = a[h][w];
    if(s.find(value)!=s.end()) return;
    if(h==H-1 && w==W-1){
        ++ans; return;
    }
    s.insert(value);
    func(h+1,w,s);
    func(h,w+1,s);
}
void solve(){ 
    cin >> H >> W;
    REP(i,H)REP(j,W) cin >> a[i][j];
    set<int> s;
    func(0,0,s);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}