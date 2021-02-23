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

// https://atcoder.jp/contests/arc110/tasks/arc110_b

// 見通しが立たないので実験

// T = 0 の場合 1 * 1e10
// T = 1 の場合 2 * 1e10

// T = 11 の場合 1 * 1e10
// T = 10 の場合 1 * 1e10
// T = 01 の場合 1 * 1e10 - 1

// T = 110 の場合 1 * 1e10
// T = 101 の場合 1 * 1e10 -1
// T = 011 の場合 1 * 1e10 -1

// T = 1101
// T = 1011
// T = 0110
// T = 1101

// 3つずらすと一巡するので
// T が部分文字列に含まれるかどうかは
// N(文字列比較) * 3 ステップで確認可能

// 含まれない場合 ans += 0
// 含まれる場合、 ans += 1e10 - (占領スペース-1) 

void solve(){ 
    ll N; cin >> N;
    string t; cin >> t;
    
    string s = "110";
    ll ans = 0LL;
    REP(start,3){
        bool isOK = true;
        REP(i,N){
            if(s[(i+start)%3]!=t[i]){
                isOK = false;
                break;
            }
        }
        if(isOK){
            ll temp = ceil((ld)(start+N)/3) - 1;
            dprint(temp);
            ans += (1e10 - temp);
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}