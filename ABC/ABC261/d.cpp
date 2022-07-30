#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc261/tasks/abc261_d
// 愚直に調べると O(2^N) で無理
// 連続ボーナスがない場合 全部表が正解
// DPかなあ
const int MAX = 5005;
ll N,M; 
ll x[MAX];
ll bonus[MAX];
ll dp[MAX][MAX]; // t回目のトスが終わった時カウンタがcだった場合に取得した金額の最大値
void solve(){ 
    // 入力
    cin >> N >> M;
    for(int t=1;t<=N;++t) cin >> x[t];
    REP(i,M){
        ll c,y; cin >> c >> y;
        bonus[c] = y;
    } 

    // 初期化
    dp[0][0] = 0;
    for(int t=1;t<=N;++t){
        // t回目のトスで裏を引く場合は t-1回目の最大値をサーチ
        dp[t][0] = 0;
        for(int c=0;c<=t-1;++c){
            chmax(dp[t][0], dp[t-1][c]);
        }

        // t回目のトスで表を引く場合は 得られる値を計算
        for(int c=1;c<=t;++c){
            dp[t][c] = dp[t-1][c-1] + x[t] + bonus[c];
        }
    }
    ll ans = 0;
    for(int c=0;c<=N;++c) chmax(ans, dp[N][c]);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}