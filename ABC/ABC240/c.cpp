#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc240/tasks/abc240_c
// dp だろう
// 到達可能な位置を控えてジャンプ
// 時間計算量は O(NX) 
int dp[105][10005];
void solve(){ 
    int N,X; cin >> N >> X;

    REP(i,N+1){
        REP(x,X+1){
            dp[i][x] = 0;
        }
    }
    dp[0][0] = 1;
    int maxReached = 0;
    for(int i=1;i<=N;++i){
        REP(choice,2){
            int a; cin >> a;
            for(int x=i-1;x<=maxReached;++x){
                if(dp[i-1][x]==0) continue;

                int next = x + a;
                if(next<=X){
                    chmax(maxReached,next);
                    dp[i][next] = 1;
                }
            }
        }
    }
    cout << (dp[N][X]?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}