#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc258/tasks/abc258_d
// 最善手は最高効率で進めるところまで進んだ後最高効率ステージを連打
// ステージi まで進んだ後ステージi 時点での連打結果を全てのステージで計算すればO(N) でいける
// N <= X であるべきことに注意
void solve(){ 
    ll N,X; cin >> N >> X;
    ll base = 0;
    ll shortest = 1e9+5;
    ll ans = shortest * 2 * X + 1;
    for(int i=1;i<=min(N,X);++i){
        ll A,B; cin >> A >> B;
        base += (A+B);
        chmin(shortest,B);
        ll cand = base + shortest * (X-i);
        chmin(ans,cand);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}