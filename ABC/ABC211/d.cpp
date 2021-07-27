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
const ll MOD = 1e9+7;
using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc211/tasks/abc211_d
// 幅優先探索
// 距離 d+1 の地点に辿りつく経路の数 = sum(距離 d かつ隣接している地点に辿りつく経路の数)
// bfs で見ていくと 距離 d+1 地点を調べる段階で距離 d 地点は全て調査済み
vector<int> neighbor[200005];
vector<int> d(200005,0);
vector<mint> c(200005,0);
void solve(){ 
    vector<int> visit(200005,0);
    int N,M; cin >> N >> M;
    REP(i,M){
        int a,b; cin >> a >> b;
        --a; --b;
        neighbor[a].emplace_back(b);
        neighbor[b].emplace_back(a);
    }
    queue<int> q;
    q.push(0);
    visit[0] = 1;
    c[0] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto y:neighbor[x]){
            if(visit[y]){
                if(d[y]==d[x]+1){
                    c[y] += c[x];
                }
            }else{
                c[y] = c[x];
                d[y] = d[x]+1;
                visit[y] = 1;
                q.push(y);
            }
        }
    }
    cout << c[N-1].val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}