#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
using mint = modint998244353;
// const ll MOD = 1e9+7;
// using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc222/tasks/abc222_d
// dp っぽい
// dp[i][x]: i 番目の数字が x であるような数列の数
mint dp[3005][3005];
ll a[3005];
ll b[3005];
mint op(mint a,mint b){ return a+b;}
mint e(){ return 0;}
segtree<mint, op, e> seg(3005);
void solve(){ 
    int N; cin >> N;
    FILL2(dp,N,3005,0);
    for(int i=1;i<=N;++i) cin >> a[i];
    for(int i=1;i<=N;++i) cin >> b[i];
    for(ll x=a[1];x<=b[1];++x){
        dp[1][x] = 1;
        for(int x=0;x<3005;++x){
            seg.set(x, dp[1][x]);
        }
    }
    for(int i=2;i<=N;++i){
        for(int x=a[i];x<=b[i];++x){
            dp[i][x] += seg.prod(0,x+1);
        }
        for(int x=0;x<3005;++x){
            seg.set(x, dp[i][x]);
        }
    }
    mint ans = 0;
    REP(x,3005){
        ans += dp[N][x];
    }
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}