#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc236/tasks/abc236_b
// map で数え上げると O(N log N)
// sum(ALL) - a_i = sum(others) を使うと O(N)
void solve(){ 
    int N; cin >> N;
    ll ans = 0;
    REP(i,N*4-1){
        ans += i%N + 1;
        ll a; cin >> a;
        ans -= a;
    }
    ans += N;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}