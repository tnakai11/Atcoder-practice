#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x) REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x) REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m) REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
     std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 998244353;
using mint = modint998244353;
// using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc210/tasks/abc210_d
// 愚直に全探索すると O( H^2 W^2 ) となり間に合わない
// min (Aij + Ai'j' + C * (i - i') + C* (j - j')v )
// = min( Aij + Ai'j' + C * (i + j) - C* (i' + j') )
// = min( Aij  + C * (i + j) + Ai'j' - C* (i' + j') )
// Ai'j' - C*(i' + j') の最小値を右下に向けて調べていけば O(HW) で解答可能

// WA
// 位置関係がこう-> / なっている場合があるので左右反転の場合も調べる必要がある 

ll a[1005][1005];
ll dp[1005][1005];
void solve(){ 
    ll H,W,C; cin >> H >> W >> C;
    CINA2(a,H,W);
    ll ans = a[0][0] + a[0][1] + C;

    REP(count,2){
        if(count==1){
            REP(h,H){
                reverse(a[h], a[h] + W);
            }
            FILL2(dp,H,W,0);
        }
        dp[0][0] = a[0][0];
        for(ll w=1;w<W;++w){
            chmin(ans, a[0][w] + C*(0+w) + dp[0][w-1]);
            dp[0][w] = min(dp[0][w-1],a[0][w] - C*(0 + w) );
        }
        for(ll h=1;h<H;++h){
            chmin(ans, a[h][0] + C*(h+0) + dp[h-1][0]);
            dp[h][0] = min(dp[h-1][0],a[h][0] - C*(h + 0) );
        }
        for(ll h=1;h<H;++h){
            for(ll w=1;w<W;++w){
                ll temp = min(dp[h-1][w],dp[h][w-1]);
                chmin(ans, a[h][w] + C*(h+w) + temp);
                dp[h][w] = min( temp, a[h][w] - C*(h + w));
            }
        }
    }

    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}