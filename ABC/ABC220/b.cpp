#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc220/tasks/abc220_b
// A,Bをそれぞれ10進法に直してから積を取る
// オーバーフローに注意する

ll convert(ll x,ll k){
    ll y = 0;
    ll b = 1;
    while(x>0){
        ll r = x%10;
        y += r * b;
        x /= 10;
        b *= k;
    }
    return y;
}

void solve(){ 
    ll K,A,B; cin >> K >> A >> B;
    if(K<10){
        A = convert(A,K);
        B = convert(B,K);
    }
    ll ans = A*B;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}