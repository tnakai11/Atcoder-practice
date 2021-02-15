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


// https://atcoder.jp/contests/arc112/tasks/arc112_b

// 0 から始めて 5 に行くには
// +(-1) * 5 : 2*5=10 円
// *(-1) : 1 円
// 合計 11 円が最小コスト
// この場合、11円あれば絶対値5以下にアクセス可能

// 5 から始めて 6 に行くには
// *(-1) : 1 円
// +(-1) * 1 : 2 円
// *(-1) : 1 円
// 合計 4 円が最小コスト
// この場合、4円あれば
// 3,4,5,6
// -4,-5,-6
// に到達可能

// 始点を中心に
// 到達可能点が生えるイメージ

// 5 から 7 に行くには
// *(-1) : 1円
// +(-1) * 2 : 4 円
// *(-1) : 1円
// 合計 6 円が最小コスト

// 操作の順序に気を付ければ
// 上がるのも下がるのもコストは同じ

// * C = 2n を使い切る場合

// X - n 以上
// X + (n-1)　以下 の範囲に到達可能

// * C = 2n + 1 を使い切る場合

// - ( X + n ) 以上
// - ( X - n ) 以下 の範囲に到達可能


pll func(ll X, ll C){
    ll n = C/2;
    if(C%2==0){
        return MP(X-n,X+(n-1));
    }else{
        return MP(-(X+n),-(X-n));
    }
}

void solve(){ 
    ll X,C; cin >> X >> C;
    ll ans = 0;

    if(C>=2){
        pll temp = func(X,C);
        ll lim1 = temp.first;
        ll lim2 = temp.second;
        
        --C;
        
        pll semp = func(X,C);
        ll lim3 = semp.first;
        ll lim4 = semp.second;

        ans += (lim2-lim1+1) + (lim4-lim3+1);
        ans -= max(min(lim2,lim4)-max(lim1,lim3)+1,0LL);
    }else{
        if(X==0){
            ans = 1;
        }else{
            ans = 2;
        }
    }

    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}