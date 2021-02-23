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

// https://atcoder.jp/contests/abc188/tasks/abc188_e

// 節を持ったグラフが複数できる
// 「一歩手前までの最安値」を保持できれば O(N+M) 程度で済みそう

const int MAX = 1000000000;
struct obj{
  int m = MAX;
  int m_idx = -1;
  int ans = -MAX;
};

vector< vector<int> > c(200005);
vector<int> a(200005);
vector<obj> d(200005); 

obj dfs(int p){
  obj res = {a[p],p,-MAX};
  for(auto x:c[p]){
    obj cand;
    if(d[x].m_idx==-1){
      cand = dfs(x);
    }else{
      cand = d[x]; 
    }
    chmax(res.ans,cand.ans);
    chmax(res.ans,a[p]-cand.m);
    if(cand.m <= res.m){
      res.m = cand.m;
      res.m_idx = cand.m_idx;
    }
  }
  d[p] = res;
  return res;
}

void solve(){
  int N,M; cin >> N >> M;
  CINA(a,N);
  REP(i,M){
    int x,y; cin >> x >> y;
    --x; --y;
    c[y].push_back(x);
  }
  REP(y,200000){
    sort(ALL(c[y]),greater<int>());
  }
  
  int ans = -MAX;
  REPR(i,N-1){
    obj temp = dfs(i);
    dprint(temp.m);
    chmax(ans,temp.ans);
  }
    
  cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}