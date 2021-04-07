#include <bits/stdc++.h>
using namespace std;
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
const ll MOD = 1e9 + 7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

// https://atcoder.jp/contests/abc177/tasks/abc177_d
// UnionFind や dfs などで各グループの人数を調べる <- 大体 O(N+M)
// 鳩の巣原理より各グループの最大人数未満に分けると条件を満たせない
// グループの最大人数が答え

struct UnionFind {
  vector<int> par,s;
  UnionFind(int N): par(N),s(N){
    REP(i,N){
      par[i] = i;
      s[i] = 1;
    }
  }
  int root(int a){
    if(par[a]==a) return a;
    par[a] = root(par[a]);
    return par[a];
  }
  void unite(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if( rx!=ry ){
      par[rx] = ry;
      s[ry] += s[rx];
    }
  }
  int size(int x){
    int rx = root(x);
    return s[rx];
  }
};

void solve(){ 
  int N,M;
  cin >> N >> M;
  UnionFind uf(N+1);
  REP(i,M){
    int a,b; cin >> a >> b;
    uf.unite(a,b);
  }
  int ans = 0;
  REP(i,N+1){
    chmax(ans,uf.size(i));
  }
  cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}