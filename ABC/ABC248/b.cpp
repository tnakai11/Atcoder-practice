#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc248/tasks/abc248_b
// A * K^n >= B
// K^n >= B/A
// n log K >= logB - log A
// n >= (log B - log A) / log K
// 丸め誤差がやや怖い...
// 愚直にシミュレートする
void solve(){ 
    ll A,B,K; cin >> A >> B >> K;
    ll n = 0;
    ll temp = A;
    while(temp<B){
        temp *= K;
        ++n;
    }
    cout << n << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}