#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;
// https://atcoder.jp/contests/abc275/tasks/abc275_b
// 普通にやると溢れる
// MODで計算する
void solve(){ 
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    mint A = a;
    mint B = b;
    mint C = c;
    mint D = d;
    mint E = e;
    mint F = f;
    mint ans = A * B * C - D * E * F;
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}