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

// https://atcoder.jp/contests/abc181/tasks/abc181_c

// 相異なる3点の組合せ全てを試すと O(N^3)
// N <= 10^2 より間に合う

// 同一直線上にある条件

// x1 != x3, x2 != x3 の場合
// (y1 - y3) / (x1 - x3) == (y2 - y3) / (x2 - x3)
// -> (y1-y3)(x2-x3) == (y2-y3)(x1-x3)

// その他の場合
// x1 = x2 = x3 (直線 x = a)

// AC
// 制約より y1==y3 && x1==x3 は満たされないので
// 場合分けは必ずしも要るわけではなかった

bool solve(){ 
    int N; cin >> N;
    vector<int> x(N),y(N);
    REP(i,N){
        cin >> x[i] >> y[i];
    }
    REP(i,N){
        for(int j=i+1;j<N;++j){
            for(int k=j+1;k<N;++k){
                if(x[i] != x[k] && x[j] != x[k]){
                    int temp = (y[i]-y[k])*(x[j]-x[k]);
                    int semp = (y[j]-y[k])*(x[i]-x[k]);
                    if(temp==semp) return true;
                }else{
                    if(x[i]==x[j] && x[j]==x[k]) return true; 
                }
            }
        }
    }
    return false;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  if(solve()==true){
      cout << Liny;
  }else{
      cout << Linn;
  }
  return 0;
}