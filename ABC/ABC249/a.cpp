#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc249/tasks/abc249_a
// 愚直にシミュレートが一番事故らなさそうではある
// X/(A+C) 回だけ B*A 進んで r=X%(A+C) だけ min(B*r,B*A) 進む
void solve(){ 
    int a[2];
    int b[2];
    int c[2];
    int X;
    REP(i,2) cin >> a[i] >> b[i] >> c[i]; 
    cin >> X;
    int l[2];
    REP(i,2){
        int block = a[i] + c[i];
        l[i] = X/block * a[i] * b[i] + min(X%block,a[i]) * b[i];
    }
    string ans = "Draw";
    if(l[0]>l[1]) ans = "Takahashi";
    if(l[0]<l[1]) ans = "Aoki";
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}