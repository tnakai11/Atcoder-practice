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

// https://atcoder.jp/contests/abc192/tasks/abc192_d

// 100_{(n)} について
// n = 2 なら 4_(10)
// n = 3 なら 9_(10)

// X の桁数が多い場合はすぐにMに届きそう

// X の桁数が 1 の場合 base が何であろうと 1桁目の値 <= M の判定
// X の桁数が 2 の場合 
// base*2桁目の値 + 1桁目の値 <= M 
// base*2桁目の値 <= M - 1桁目の値
// base <= (M-1桁目の値)/(2桁目の値)

// 1ケースだけTLE

// X の桁数が 3 の場合
// base*base * v[0] + base * v[1] + v[2] <= M
// v[0] base^2 + v[1] base + (v[2]-M) <= 0


void solve(){ 
    string X; cin >> X;
    ll N = X.size();
    vector<ll> v(N);
    REP(i,N){
        v[i] = (ll)ctoi(X[i]);
    }

    ll M; cin >> M;
    ll ans = 0;
    if(N==1){
        if(v[0]<=M){
            ans = 1;
        }
    }else{
        ll d = *max_element(ALL(v));
        if(N==2){
            ll cand = (M - v[1])/v[0] - d;
            chmax(ans,cand);
        }else if(N==3){
            ll D = v[1]*v[1] - 4 * v[0] * (v[2]-M);
            if(D>=0){
                ll alpha = (- v[1] - sqrt(D))/(2*v[0]);
                ll beta = (- v[1] + sqrt(D))/(2*v[0]);
                ll left = max(alpha,d+1);
                ll right = max(beta,d+1);
                chmax(ans, right-left+1);
            }
        }else{
            for(ll n=d+1;;++n){
                ll x = 0;
                for(ll e:v){
                    if(x * n > M - e){
                        x = M+1; break;
                    }
                    x = x * n + e;
                }
                if(x<=M){
                    ++ans;
                }else{
                    break;
                }
            }
        }
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}