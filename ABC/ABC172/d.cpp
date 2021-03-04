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

// https://atcoder.jp/contests/abc172/tasks/abc172_d

// 約数の個数を前処理なしで求めようとすると
// 計算量は O(√N) 
// N <= 10^7 よりこの方法では間に合わない

// エラトステネスの篩と同様の方法で
// SPF(Smallest Prime Factor) を事前に求めておく( O(N log log N) ) と
// 各Kについて O(log K) で約数のカウントが可能
// この方法なら計算量は O(N log N) となり間に合う

// 手元の環境では実行にやや時間がかかった
// サーバ側では通るっぽいのでいいか...

// AC
// 昔の解法を見ると spf を使わず直接計数していた
// 直接計数するパターンで式をいじると O(N) で解けるそう

vector<int> spf(10000005);

void solve(){ 
    ll N; cin >> N;
    
    REP(i,N+1) spf[i] = i;
    for(int i=2;i*i<=N;++i){
        if(spf[i]==i){
            for(int j=2;i*j<=N;++j){
                chmin(spf[i*j],i);
            }
        }
    }

    ll ans = 0LL;
    for(ll k=1;k<=N;++k){
        map<ll,ll> mp;
        ll temp = k;
        while(temp != 1){
            ++mp[spf[temp]];
            temp /= spf[temp];
        }
        ll elem = k;
        for(const auto& [key, value] : mp){
            elem *= (value+1);
        }
        ans += elem;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}