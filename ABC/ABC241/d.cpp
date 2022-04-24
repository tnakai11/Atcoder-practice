#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc241/tasks/abc241_d
// ソート済み数列が得られれば理想的
// プライオリティーキューでは取り出すのに時間がかかるが毎回ソート...？
// とりあえず書いて投げてみる -> TLE
// multiset ならばどうか -> AC
const ll MAX = 1e18 + 1;
const ll MIN = -1;
void solve(){ 
    ll Q; cin >> Q;
    multiset<ll> a;
    REP(i,10){ a.insert(MIN); }
    REP(i,10){ a.insert(MAX); }
    REP(count,Q){
        ll c; cin >> c;
        if(c==1){
            ll x; cin >> x;
            a.insert(x);
            continue;
        }
        if(c==2){
            ll x; cin >> x;
            ll K; cin >> K;
            auto itr = a.upper_bound(x);
            REP(k,K){
                --itr;
            }
            ll ans = *itr;
            if(ans==MIN || ans==MAX) ans = -1;
            cout << ans << '\n';
        } 
        else if(c==3) {
            ll x; cin >> x;
            ll K; cin >> K;
            auto itr = a.lower_bound(x);
            REP(k,K-1){
                ++itr;
            }
            ll ans = *itr;
            if(ans==MIN || ans==MAX) ans = -1;
            cout << ans << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}