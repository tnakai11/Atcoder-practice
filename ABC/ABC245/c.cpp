#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc245/tasks/abc245_c
// 全パターンを調べると　O(2^N) となり無理
// dp でなんとかしたい
// dp[i][j] ... i 番目の数として数列 j (A or B) を選ぶことが可能であるか
void solve(){ 
    int N,K; cin >> N >> K;

    int x[N+1][2];
    REP(j,2) REP(i,N)  cin >> x[i+1][j];

    int dp[N+1][2];
    REP(i,N+1) REP(j,2) dp[i][j] = 0;

    // DP
    REP(j,2) dp[1][j] = 1;
    for(int i=2;i<=N;++i){
        REP(j,2){
            if(dp[i-1][j]==0){
                continue;
            }
            REP(k,2){
                int cand = x[i][k];
                int pre = x[i-1][j];
                if( abs(cand - pre)<=K){
                    dp[i][k] = 1;
                }
            }
        }
    }
    int ok = dp[N][0] + dp[N][1];
    cout << (ok?Liny:Linn);

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}