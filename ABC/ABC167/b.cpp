#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc167/tasks/abc167_b
// 点数が大きいカードから貪欲で取っていく
// 愚直にシミュレーションするとO(N)となり間に合わないので掛け算で捌く
void solve(){ 
    ll A,B,C,K; cin >> A >> B >> C >> K;
    ll ans = 0LL;
    ll temp = min(K,A);
    ans += temp;
    K -= temp;
    temp = min(K,B);
    K -= temp;
    temp = min(K,C);
    ans -= temp;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}