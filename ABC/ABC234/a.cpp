#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc234/tasks/abc234_a
// 文字式を頑張っていじれば計算量を落とせる気がしないでもないが
// 面倒なので値を直接計算する
ll f(ll x){
    return x*x + 2 * x + 3;
}
void solve(){ 
    ll t; cin >> t;
    ll ans = f( f( f(t) + t ) + f( f(t) ) );
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}