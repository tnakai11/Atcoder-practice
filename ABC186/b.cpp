#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repr(i,n) for(int i=n; i>-1; --i)
#define all(a) (a).begin(),(a).end()
#define fill(a,n,x) rep(i,(n)){ (a)[i]=(x); }
#define cina(a,n) rep(i,(n)){ cin >> (a)[i]; }
#define fill2(a,n,m,x) rep(i,(n)){ rep(j,(m)){(a)[i][j]=(x);} }
#define cina2(a,n,m) rep(i,(n)){ rep(j,(m)){cin >> (a)[i][j];} }
#define liny "yes\n"
#define linn "no\n"
#define liny "yes\n"
#define linn "no\n"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll n){ return accumulate(a,a+n,0ll);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class t> void chmax(t& a, t b){ if(a<b){a=b;} }
template<class t> void chmin(t& a, t b){ if(a>b){a=b;} }
template<class t> bool isin(t a,vector<t> v){ for(t x:v){ if(a==x){return true;}} return false;}
string strreplace(string s,string target, string replacement){
    if (!target.empty()) {
     std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll mod = 998244353;
using mint = modint998244353;
// using mint = static_modint<mod>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
bool debug = 0;
template<class t> void dprint(t s){
  if(debug){ cout << s << "\n"; }
}

// https://atcoder.jp/contests/abc186/tasks/abc186_b

// 最小値を求める
// 愚直でok
// 無駄を省くなら sum(a) - min(a) * h * w 

int a[105][105];

void solve(){ 
    int h,w; cin >> h >> w;
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    int s = 0;
    int m = 500;
    rep(i,h){
        rep(j,w){
            s += a[i][j];
            chmin(m,a[i][j]);
        }
    }
    int ans = s - m * h * w;
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='d'){ debug = 1;}
  solve();
  return 0;
}