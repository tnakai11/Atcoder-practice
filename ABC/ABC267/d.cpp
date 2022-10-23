#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
// https://atcoder.jp/contests/abc267/tasks/abc267_d
// 愚直にやると O(N_C_M *M)
// 2000_C_1000 > 2 * 10^600 なので愚直は無理
// dp かな
// dp[i][j] ... Ai の時点で j 個確定させたときの最大値
// 1,3,2,5
// dp[1][1] = a[1] = 1
// dp[2][1] = max(dp[1][1],a[2]) = 3
// dp[2][2] = max(dp[1][2],[dp[1][1] + a[2]*2) = 7
// dp[3][1] = max(dp[2][1],dp[2][0]+2) = 3
// dp[3][2] = max(dp[2][2],dp[2][1]+2*a[3]) = 7
// dp[3][3] = max(dp[2][3],dp[2][2]+3*a[3])
ll a[2005];
ll dp[2005][2005];
void solve(){ 
    ll N,M; cin >> N >> M;
    REP(i,N+1) REP(j,M+1) dp[i][j] = 0;
    for(ll i=1;i<=N;++i) cin >> a[i];
    for(ll i=1;i<=N;++i){
        for(ll j=1;j<=M;++j){
            dp[i][j] = dp[i-1][j-1] + j*a[i];
            if(i==j) break; // i-1<j のケースを避ける
            chmax(dp[i][j],dp[i-1][j]);
        }
    }
    ll ans = dp[N][M];
    cout << ans << '\n';
    
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}