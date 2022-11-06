#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
typedef long long ll;
// https://atcoder.jp/contests/abc275/tasks/abc275_d
// メモ化すればいけそう
map<ll,ll> mp;
ll N;
ll func(ll x){
    if(x==0) return 1;
    if(mp[x]>0) return mp[x];
    ll v = func(x/2) + func(x/3);
    mp[x] = v;
    return v;
}
void solve(){ 
    cout << func(N) << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  cin >> N;
  solve();
  return 0;
}