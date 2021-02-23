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

// https://atcoder.jp/contests/abc181/tasks/abc181_d

// |S| = 1 の場合 
// S = "8" であるかどうか(O(1))

// |S| = 2 の場合
// S[0]S[1] か S[1]S[0] が8の倍数であるかどうか(O(1))

// |S| >= 3 の場合
// 1000 が 8 の倍数であることから
// 3 桁の 8 の倍数を構成できるかどうか(O(N))

bool solve(){ 
    string s; cin >> s;
    int N = s.size();
    vector<int> v(N);
    REP(i,N){
        v[i] = ctoi(s[i]);
    }

    if(N==1){
        return (v[0]==8);
    }
    if(N==2){
        int x = v[0] * 10 + v[1];
        int y = v[1] * 10 + v[0];
        return (x%8==0 || y%8==0);
    }

    map<int,int> mp;
    REP(i,N){
        ++mp[v[i]];
    }

    for(int i=1;i<1000;++i){
        int temp = i*8;
        if(temp<100) continue;
        if(temp>1000) break;
        map<int,int> np;
        while(temp>0){
            ++np[ temp%10 ];
            temp /= 10;
        }
        bool isOK = true;
        REP(i,10){
            if(mp[i]<np[i]){
                isOK = false;
                break;
            }
        }
        if(isOK) return true;
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