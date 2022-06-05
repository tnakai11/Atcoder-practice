#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc253/tasks/abc253_d
// 包除原理かな
// ans = 1~N の総和 - Aの倍数の総和 - Bの倍数の総和 + AB の倍数の総和?
// A=2, B=4 などのケースが厳しい
// 場合分けかなあ
// WA
// N,A,B の関係に制約がないのか
// N<A の場合も N/x = 0 でカバーできるはず
// A*B が大きすぎるパターンか...?
// lcm か
ll N;
ll func(ll x){
    ll res = N/x * (x + N/x*x)/2;
    return res;
}
void solve(){ 
    ll A,B; cin >> N >> A >> B;
    ll ans = 0LL;
    ans += func(1);
    ans -= func(A);
    ans -= func(B);
    ans += func(lcm(A,B));
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}