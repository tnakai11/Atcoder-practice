#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
using mint = modint998244353;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc238/tasks/abc238_c
// Nが大きいので愚直は厳しい
// f(1) = 1
// ...
// f(9) = 9
// f(10) = 1
// ..
// f(19) = 10
// f(20) = 11
// ...
// f(99) = 90
// i=1~9 ... sum(1~9)
// i=10~99 ... sum(1~90)
// i=100~999 ... sum(1~900)
// i=1000~9999 ... sum(1~9000)

ll keta(ll N){
    int k = 0;
    while(N>0){
        N /= 10;
        ++k;
    }
    return k;
}

void solve(){ 
    ll N; cin >> N;
    ll K = keta(N);
    mint ans = 0;
    for(ll k=1;k<K;++k){
        mint n = 9 * (ll)pow(10,k-1);
        ans += n * (1+n) / 2;
    }
    mint m = N - (ll)( (ll)pow(10,K-1) - 1);
    ans += m * (1+m)/2;
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}