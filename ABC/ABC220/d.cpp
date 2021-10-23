#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x) REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
using mint = modint998244353;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc220/tasks/abc220_d
// 全探索はまず無理である
// dp かなあ
// i 回目の操作で左端に x を生み出す通り数
mint dp[100005][15];
int a[100005];
void solve(){ 
    int N; cin >> N;
    CINA(a,N);
    FILL2(dp,N,10,0);
    dp[0][ a[0] ] = 1;
    for(int i=1;i<N;++i){
        for(int k=0;k<10;++k){
            int f = (k+a[i])%10;
            int g = (k*a[i])%10;
            dp[ i ][ f ] += dp[ i-1 ][ k ];
            dp[ i ][ g ] += dp[ i-1 ][ k ];
        }
    }
    for(int k=0;k<10;++k){
        mint ans = dp[N-1][k];
        cout << ans.val() << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}