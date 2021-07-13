#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
const ll MOD = 1e9+7;
using mint = static_modint<MOD>;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc209/tasks/abc209_c
// 愚直に検討すると O(N^2)
// ソートして下から埋めていけば O(N log N)
void solve(){ 
    ll N; cin >> N;
    vector<ll> c(N); CINA(c,N);
    sort(ALL(c));
    mint ans = 1;
    REP(i,N){
        ans *= (c[i]-i);
    }
    cout << ans.val() << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}