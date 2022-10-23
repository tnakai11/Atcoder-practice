#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
// https://atcoder.jp/contests/abc267/tasks/abc267_c
// 愚直に調べると M*(N-M) 回の計算が必要
// N=2*10^5, M=N/2 できつい
// M=4 の場合
// a1, a2, a3, a4
//     a2, a3, a4
//         a3, a4
//             a4
// a2, a3, a4, a5
//     a3, a4, a5
//         a4, a5
//             a5
// C2 = C1 - a1 - a2 - a3 - a4 + a5 *4
// 累積和を控えておけば引き算部分を一発で出せるので O(N) に抑えられる
ll a[200005];
ll cumu[200005];
void solve(){ 
    ll N,M; cin >> N >> M;
    cumu[0] = 0;
    for(int i=1;i<=N;++i){
        ll x; cin >> x;
        a[i] = x;
        cumu[i] = cumu[i-1] + x;
        if(DEBUG) printf("%Ld ",cumu[i]);
    }
    if(DEBUG) cout << "\n";
    ll ans = 0;
    for(int i=1;i<=M;++i){
        ans += i*a[i];
    }
    ll preCand = ans;
    for(int i=2;i+M-1<=N;++i){
        int j=i+M-1;
        ll temp = cumu[j-1] - cumu[i-2];
        ll cand = preCand - temp + M*a[j];
        if(DEBUG) printf("%Ld %Ld\n",i,cand);
        chmax(ans,cand);
        preCand = cand;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}