#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc248/tasks/abc248_c
// 問題を以下のように読み換える
// k(<=K) 個の区別できないボールを N-1 個の区別できない仕切りで仕切る
// 仕切りの間隔を1以上M以下とするとき
// ボールと仕切りの並べ方を数え上げよ
//
// k-N(<=K-N) 個の区別できないボールを N-1 個の区別できない仕切りで仕切る
// 仕切りの間隔を0以上M-1以下とするとき
// ボールと仕切りの並べ方を数え上げよ
//
// 制限なしの数え上げ( _(K-N+N-1)C_(N-1) )から間隔M以上の仕切りが存在するパターンを除去...？
// 
// Nが小さいので DP でいけないだろうか
// dp[i][j] A_i を選んだ時に値が　j となるパターン数
mint dp[55][5000];
void solve(){ 
    int N,M,K; cin >> N >> M >> K;

    // i=1;
    for(int j=1;j<=M;++j) dp[1][j] = 1;

    for(int i=2;i<=N;++i){
        for(int before=1;before<=N*M+1;++before){
            for(int a=1;a<=M;++a){
                int j = before + a;
                if(j>K) break;
                dp[i][j] += dp[i-1][before];
            }
        }
    }

    mint ans = 0;
    for(int j=N;j<=K;++j){
        ans += dp[N][j];
        if(DEBUG) cout << j << ' ' << dp[N][j].val() << '\n';
    }
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}