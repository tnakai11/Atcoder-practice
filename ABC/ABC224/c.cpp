#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define pll pair<ll,ll>
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc224/tasks/abc224_c
// 全探索で O(N^3)
// (y3 - y1) / (x3 - x1) = (y2 - y1) / (x2 - x1) なら不適
// <-> (y3 - y1)(x2 - x1) = (y2 - y1)(x3 - x1)   なら不適
void solve(){ 
    ll N; cin >> N;
    pll p[N];
    REP(i,N) cin >> p[i].first >> p[i].second;
    ll ans = 0LL;
    REP(i,N) {
        ll x1 = p[i].first;
        ll y1 = p[i].second;
        for(int j=i+1;j<N;++j) {
            ll x2 = p[j].first;
            ll y2 = p[j].second;
            for(int k=j+1;k<N;++k){
                ll x3 = p[k].first;
                ll y3 = p[k].second;
                ll temp = (y3 - y1) * (x2 - x1);
                ll semp = (y2 - y1) * (x3 - x1);
                if(temp!=semp) ++ans;
            }
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}