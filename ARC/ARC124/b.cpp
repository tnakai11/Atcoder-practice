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
// https://atcoder.jp/contests/arc124/tasks/arc124_b
// x の全探索は無理筋
// b の並び替え全パターンも無理
// a1 とペアになる bi は高々2000パターンなので K<=2000
// a1^bi = a2^bj = a3^bk = x が成り立つとき
// a1^a1^bi = bi = a1^x
// a2^a2^bj = bj = a2^x
// a3^a3^bk = bk = a3^x
// a に x を xor して b を構成できるか調べれば
//  O(N^2 log N) ぐらいでいける
// WA 重複に注意
void solve(){ 
    set<ll> ans;
    int N; cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    CINA(a,N);
    CINA(b,N);
    sort(ALL(a));
    sort(ALL(b));
    REP(idxCand,N){
        ll x = a[0]^b[idxCand];
        vector<ll> v(N); // a xor x
        REP(j,N){
            v[j] = a[j]^x;
        }
        sort(ALL(v));
        bool ok = true;
        REP(j,N){
            if(b[j]!=v[j]){
                ok = false;
            }
        }
        if(ok) ans.insert(x);
    }
    cout << ans.size() << '\n';
    for(auto x:ans){
        cout << x << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}