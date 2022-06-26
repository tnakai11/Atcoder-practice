#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc256/tasks/abc256_b
// マス数が少ないのでいちいちシミュレーションするのでOKそう
// 累積和を後ろから取ればO(N)で解けるはず
int a[105];
int cumu[105];
void solve(){ 
    // input 
    int N; cin >> N;
    for(int i=1;i<=N;++i){
        cin >> a[i];
    }
    // setup
    cumu[N+1] = 0;
    for(int i=N;i>=1;--i){
        cumu[i] = cumu[i+1] + a[i];
    }
    // count
    int ans = 0;
    for(int i=1;i<=N;++i){
        if(cumu[i]>=4) ++ans;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}