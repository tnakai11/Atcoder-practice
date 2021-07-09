#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define FILL(a,n,x) REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc167/tasks/abc167_c
// 選ぶ参考書のパターンを全探索すれば O(M 2^N)
// 12 * 2^12 = 12 * 4^6 < 4^8 = 16^4 = 256^2 < 10^6 なので計算可能
ll c[20];
ll a[20][20];
ll r[20];
void solve(){ 
    ll N,M,X; cin >> N >> M >> X;
    REP(i,N){
        cin >> c[i];
        REP(j,M){
            cin >> a[i][j];
        }
    }
    ll ans = -1;
    for(ll bits=0;bits<(1<<N);++bits){
        ll cand = 0;
        FILL(r,M,0LL);
        for(ll i=0;i<N;++i){
            if((bits>>i)&1){
                cand += c[i];
                REP(j,M){
                    r[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        REP(j,M){
            if(r[j]<X){
                ok = false; break;
            }
        }
        if(ok) {
            if(ans==-1) ans = cand;
            else chmin(ans,cand);
        }
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}