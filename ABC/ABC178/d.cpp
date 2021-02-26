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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
#define IFD if(DEBUG)
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

// https://atcoder.jp/contests/abc178/tasks/abc178_d
// Sがそれほど大きくないので
// 数列の項数を縛ることができそう
// 項数をnとしてSから3n徴収した後、
// 残りのxをn項に分配 (x+n-1)C(n-1)

const ll MOD = 1e9+7;
using mint = static_modint<MOD>;
const int MAX = 30000000;
ll f[MAX],finv[MAX],inv[MAX];
void COMinit(int N){
    f[0] = 1;
    f[1] = 1;
    finv[0] = 1;
    finv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<=N;++i){
        f[i] = f[i-1]*i %MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) %MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int N, int K){
    if(N<K || N<0 || K <0){ return 0; }
    return f[N]*(finv[K]*finv[N-K]%MOD) %MOD;
}

void solve(){ 
    ll S; cin >> S;
    COMinit(S);
    mint ans = 0;
    for(ll n=1;n<1000;++n){
        ll x = S - 3 * n;
        if(x<0) break;
        ans += COM(x+n-1,n-1); 
    }
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}