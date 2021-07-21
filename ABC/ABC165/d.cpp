#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc165/tasks/abc165_d
// Ax = Br + q (q<B) とおくと
// Ax/B = r + q/A
// x/B = r/A + q/(AB)だから
// obj 
// = floor(AX/B) - A * floor(x/B)
// = r - A * floor(r/A)
// r = An + m (m<A) とおくと 
// obj = An + m - A*n = m
// よって r を A で割った余りの最大値が答え

// r=0~A-1 で Ax = Br + q を満たす x, q を作れるか調べる

// AC
// 解説を読む
// 0 <= x <= B-1 において目的の関数は単調増加。またf(x+B) = f(x)
// f( min(B-1, N) ) が答え

void solve(){ 
    ll A,B,N; cin >> A >> B >> N;
    ll ans = 0;
    ll temp;
    for(ll r=0;r<=A-1;++r){
        ll x = B*r / A;
        if(x>N) continue;
        temp = A*x - B*r;
        if(0<= temp && temp < B){ chmax(ans,r); } 
        if(++x>N) continue;
        temp = A*x - B*r;
        if(0<= temp && temp < B){ chmax(ans,r); } 
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}