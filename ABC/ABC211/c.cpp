#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define FILL2(a,n,m,x) REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
const ll MOD = 1e9+7;
using mint = static_modint<MOD>;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

// https://atcoder.jp/contests/abc211/tasks/abc211_c
// DP でいけば OK
// mod を忘れずに

mint dp[100005][8];
void solve(){ 
    string s; cin >> s;
    string t = "chokudai";
    int N = s.size();
    FILL2(dp,N+1,8,0);
    REP(i,N){
        char c=s[i];
        REP(j,8){
            dp[i+1][j] = dp[i][j];
            if(t[j]==c){
                if(j==0){
                    dp[i+1][j] += 1;
                }else{
                    dp[i+1][j] += dp[i][j-1];
                }
            }
        }
    }
    if(DEBUG){
        REP(i,N+1){
            cout << dp[i][7].val() << ' ';
        }
        cout << endl;
    }
    cout << dp[N][7].val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}