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

// https://atcoder.jp/contests/abc171/tasks/abc171_c
// 26進数ぽい

// 0-indexed で考えてみる

// a,b,c だけで名づけをする場合
// a,b,c (0,1,2)
// aa,ab,ac (3*1+0, 3*1+1, 3*1+2)
// ba,bb,bc (3*2+0, 3*2+1, 3*2+2)
// ca,cb,cc (3*3+0, 3*3+1, 3*3+2)
// aaa (9*1+3*1+0)

// 1の位が変

// '' = 0 とみなして 1-indexed を考えると

// _,  a, b  (0,1,2)
// c_, aa, ab  (3+0, 3*1+1, 3*1+2)
// ac_, ba, bb (3*1+3+0, 3*2+1, 3*2+2) 

// a~c を拾うには (temp-1)%3 を計算
// a~z を拾うには (temp-1)%26 を計算
// temp = (temp-1)/26 で使った値を落とせる

// 全体の計算量は O(log N)

void solve(){ 
    ll N; cin >> N;
    string ans = "";
    while(N){
        dprint(N);
        ll r = (N-1)%26;
        ans += string(1,(char)('a'+r));
        N = (N-1)/26;
    }
    reverse(ALL(ans));
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}