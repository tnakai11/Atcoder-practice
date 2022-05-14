#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc246/tasks/abc246_c
// 減額 X を無駄なく消費したい
// 頭から X ずつ減額後 残額が多い順に sort してもう一周
void solve(){ 
    ll N,K,X; cin >> N >> K >> X;
    vector<ll> a(N);
    REP(i,N) cin >> a[i];

    ll coupon = K;
    REP(i,N){
        ll couponUse = min( a[i]/X , coupon);
        a[i] -= couponUse * X;
        coupon -= couponUse;
        if(coupon==0) break;
    }
    sort(ALL(a),greater<ll>());

    ll ans = 0;
    for(int i=coupon;i<N;++i){
        ans += a[i];
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}