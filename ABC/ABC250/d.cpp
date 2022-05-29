#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc250/tasks/abc250_d
// 探索するべき空間はたぶん狭い
// N^(1/3) 未満の素数で全探索
void solve(){ 
    ll N; cin >> N;
    vector<ll> v;
    map<ll,int> mp;
    mp[0] = 1;
    mp[1] = 1;
    for(ll x=2;x*x<N/x || (x*x==N/x && N%x==0);++x){
        if(mp[x]) continue;
        v.emplace_back(x);
        for(ll temp = x; temp*temp<N/temp || (temp*temp==N/temp && N%temp==0) ; temp+=x){
            mp[temp] = 1;
        }
    }
    int M = v.size();
    ll ans = 0;
    for(int i=0;i<M;++i){
        ll p = v[i];
        for(int j=i+1;j<M;++j){
            ll q = v[j];
            // if(p*q*q*q>N) break;
            // else{ ++ans; }
            if(q*q*q>N/p) break;
            if(q*q*q==N/p && N%p>0 ){ break; }
            if(q*q*q==N/p && N%p==0 ){ ++ans; }
            if(q*q*q<N/p){ ++ans; }
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}