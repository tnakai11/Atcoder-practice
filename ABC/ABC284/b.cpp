#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc284/tasks/abc284_b
// 各Aiについて偶奇判定をするだけなのでO(TN)で通せる
void solve(){ 
    int T; cin >> T;
    REP(t,T){
        int N; cin >> N;
        int ans = 0;
        REP(i,N){
            int a; cin >> a;
            if(a%2==1) ++ans;
        }
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}