#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc233/tasks/abc233_d
// 累積和と 尺取り法でいけると思いきや負の数がありだった
// 累積和を map しておけば進みながら K を構成できるか調べられそう
void solve(){ 
    ll N,K; cin >> N >> K;
    map<ll,ll> mp;
    ll ans = 0;

    ll cumu = 0;
    ++mp[cumu];

    REP(i,N){
        ll a; cin >> a;
        cumu += a;
        ll b = cumu - K;
        if(mp[b]>0){
            ans += mp[b];
        }
        ++mp[cumu];
        dprint(ans);
    }

    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}