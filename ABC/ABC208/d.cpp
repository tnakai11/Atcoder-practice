#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define FILL2(a,n,m,x) REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }

bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc208/tasks/abc208_d
// ワーシャルフロイド法を適用すると O(N^3) で解答可能

int d[405][405];
int MAX = pow(10,9);
void solve(){ 
    int N,M; cin >> N >> M;
    FILL2(d,405,405,MAX);
    REP(i,N) d[i][i] = 0;
    REP(count,M){
        int a,b,c; cin >> a>> b>> c;
        --a; --b;
        d[a][b] = c;
    }
    ll ans = 0LL;
    REP(k,N){ // 経由点
        REP(i,N){ // 始点
            REP(j,N){ // 終点
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
        REP(i,N) REP(j,N) if(d[i][j]<MAX) ans += d[i][j];
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}