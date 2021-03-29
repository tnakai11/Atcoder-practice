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

// https://atcoder.jp/contests/abc195/tasks/abc195_d
// 1. 価値が大きい順
// 2. 重さが小さい順
// にソートすれば貪欲で解けそう

// 使用可能な箱は許容重量が小さい順にソート

// 計算量 O(N logN + Q (M log M + MN ) )

// AC
// 実装がやや面倒だった

struct item {
  int w,v;
};

bool func(item a,item b){
  if(a.v!=b.v) return a.v > b.v;
  return a.w < b.w;
}

void solve(){ 
  int N,M,Q; cin >> N >> M >> Q;
  vector<item> v(N); REP(i,N) cin >> v[i].w >> v[i].v; sort(ALL(v),func);
  int x[M]; CINA(x,M);

  REP(q,Q){
    int L,R; cin >> L >> R;
    --L;--R;
    vector<int> cs;
    for(int i=0;i<L;++i){
      cs.emplace_back(x[i]);
    }
    for(int i=R+1;i<M;++i){
      cs.emplace_back(x[i]);
    }
    sort(ALL(cs));

    int ans = 0;
    for(auto e:v){
      for(int i=0;i<cs.size();++i){
        if(e.w<=cs[i]){
          ans += e.v;
          cs[i] = -1;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}