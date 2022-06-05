#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc253/tasks/abc253_e
// dp っぽい
// dp[i][j] Ai の値が j であるような数列の数
// dp[i][j] を愚直に求めると O(NM^2)
// 累積和を使えば O(NM)
int N,M,K;
mint dp[1005][5005];
mint func(int i,int j){
    int lBorder = j-(K-1);
    int rBorder = j+(K-1);
    if(DEBUG) printf("j=%d,k=%d,l=%d,r=%d\n",j,K,lBorder,rBorder);
    mint res = 0;
    if(lBorder > rBorder){
        res = dp[i-1][M];
        dprint('z');
    }else if(1< lBorder && rBorder<M){
        res += dp[i-1][M];
        res -= dp[i-1][rBorder];
        res += dp[i-1][lBorder-1];
        dprint('a');
    }else if(rBorder < M){
        res += dp[i-1][M];
        res -= dp[i-1][rBorder];
        dprint('b');
    }else if(1 < lBorder){
        res += dp[i-1][lBorder-1];
        dprint('c');
    }
    dprint(res.val());
    return res;
}
void solve(){ 
    cin >> N >> M >> K;
    
    for(int j=1;j<=M;++j){
        dp[1][j] = dp[1][j-1] + 1;
    } 
    for(int i=2;i<=N;++i){
        for(int j=1;j<=M;++j){
            dp[i][j] = dp[i][j-1] + func(i,j);
        }
    }
    if(DEBUG){
        for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) cout << dp[i][j].val() << (j<M?' ':'\n');
    }
    mint ans = dp[N][M];
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}