#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// https://atcoder.jp/contests/abc277/tasks/abc277_a
// やるだけ
// for 文が書けたらOK
void solve(){ 
    int N,X; cin >> N >> X;
    int p[N];
    REP(i,N) cin >> p[i];
    int ans = 0;
    REP(i,N){
        if(p[i]==X){
            ans = i + 1;
            break;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}