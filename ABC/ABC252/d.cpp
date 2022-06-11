#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc252/tasks/abc252_d
// 愚直に書くとO(N^3)で辛い
// 組の総数 - 3つ一致する組数 - 2つ一致する組数
ll solveSimply(ll N,vector<ll> a){
    ll ans = 0;
    REP(i,N){
        for(int j=i+1;j<N;++j){
            for(int k=j+1;k<N;++k){
                if(a[i]==a[j]) continue;
                if(a[j]==a[k]) continue;
                if(a[k]==a[i]) continue;
                ++ans;
            }
        }
    }
    return ans;
}
ll nc2(ll N){
    return N*(N-1)/2;
}
ll nc3(ll N){
    return N*(N-1)/2*(N-2)/3;
}
ll solve(ll N,vector<ll> a){ 
    map<int,ll> mp;
    for(ll e:a){
        ++mp[e];
    }
    ll ans = nc3(N);
    for(const auto &item: mp){
        ll value = item.second;
        ans -= nc3(value);
        ans -= nc2(value) * (N-value);
    }
    return ans;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  ll N; cin >> N;
  vector<ll> a(N); REP(i,N) cin >> a[i];
  if(DEBUG) cout << solveSimply(N,a) << '\n';
  cout << solve(N,a) << '\n';
  return 0;
}