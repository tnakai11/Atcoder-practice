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
// https://atcoder.jp/contests/arc124/tasks/arc124_a
// 先に確定できるものを確定させてから数え上げ
// 左にRがいくつあるか と 右にLがいくつあるか

char c[1005];
ll k[1005];
vector<ll> ls(1005,0);
vector<ll> rs(1005,0);
void solve(){ 
    ll N,K; cin >> N >> K;
    REP(i,K) {
        cin >> c[i] >> k[i];
    }
    REP(i,K){
        dprint(i); 
        int idx = k[i];
        if(ls[idx] || rs[idx]) {
            cout << 0 << '\n';
            return;
        }
        if(c[i]=='R'){
            rs[ idx ] = 1;
        }else{
            ls[ idx ] = 1;
        }
    }
    for(int idx=1;idx<=N;++idx){
        rs[idx] += rs[idx-1]; // 1 ~ N
    }
    for(int idx=N;idx>=1;--idx){
        ls[idx] += ls[idx+1]; // N ~ 1
    }
    REP(i,K){
        int idx = k[i];
        if(c[i]=='R') rs[idx] = -1;
        else ls[idx] = -1;
    }

    mint ans = 1;
    for(int idx=1;idx<=N;++idx){
        if(DEBUG){ cout << idx << ':' << rs[idx]  << ' ' << ls[idx] << '\n';}
        if(ls[idx]<0 || rs[idx]<0) continue;
        ans *= max(K-ls[idx]-rs[idx],0LL);
    }
    cout << ans.val() << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}