#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
typedef long long ll;
// https://atcoder.jp/contests/abc273/tasks/abc273_b
// 1445 とかは順にくり上がって2000
// 順番にちゃんとやろう
ll f(ll x, ll i){
    ll ord = pow(10,i);
    ll overI = x / ord;
    ll overIp1 = overI/10 + (overI%10>=5);
    return overIp1 * ord * 10;
}
void solve(){ 
    ll X,K; cin >> X >> K;
    ll ans = X;
    for(int i=0;i<=K-1;++i) ans = f(ans, i);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}