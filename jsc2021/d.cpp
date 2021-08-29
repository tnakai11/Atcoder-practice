#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll MOD = 1e9+7;
using mint = static_modint<MOD>;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_d
// x mod P の列に値を加える時、踏んでいけないのは P - x のみ
// つまり加える値の選択肢は P-2 個ある
// 最初の値の選択肢は P-1 個なので (P-1)*(P-2)^{N-1} が答え
mint mpow(mint x,ll n){
    if(n==0) return 1;
    if(n==1) return x;
    if(n%2==0) return mpow(x*x,n/2);
    return mpow(x,n-1)*x;
}
void solve(){ 
    ll N,P; cin >> N >> P;
    mint ans = mpow(P-2,N-1)*(P-1);
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}