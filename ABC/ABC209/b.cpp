#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc209/tasks/abc209_b
// いちいちシミュレーションしてもまとめて計算しても計算量は O(N)
void solve(){ 
    ll N,X; cin >> N >> X;
    ll s = 0LL;
    REP(i,N){
        ll a; cin >> a;
        s += a;
    }
    s -= N/2;
    if(X>=s) cout << Liny;
    else cout << Linn;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}