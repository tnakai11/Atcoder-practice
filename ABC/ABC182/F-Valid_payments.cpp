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
// https://atcoder.jp/contests/abc182/tasks/abc182_f
// 気持ち
// ある桁のみで構成した値 (y) == ( X + 他の桁のみで構成した値(おつり) )
// が成り立つようなパターンを数える
// 桁を切る...？

// 解説を見た 
// 桁DPっぽい
// 下から端数を{除くor埋める}イメージ

ll N,X; 
ll a[60]; 
ll dp[60][2]; // i番目までの硬貨を使用したときに過払い状態で{j?ある:ない}場合の数
void solve(){ 
    cin >> N >> X;
    CINA(a,N);
    FILL2(dp,60,2,0LL);
    dp[0][0] = 1LL;

    REP(idx,N-1){
        ll numPayLeast =       X/a[idx]; // 最低限必要そうなコインの枚数
        ll numContain = a[idx+1]/a[idx]; // 上位のコインは現在のコイン何枚相当か
        REP(add,2){
            ll numPay = numPayLeast + add; 
            if(numPay % numContain == 0){ // この桁は0なので状態変化なし 
                dp[idx+1][add] += dp[idx][add];  
            }else{ // 過払い状態とそうでない状態とに遷移できる 
                dp[idx+1][0] += dp[idx][add]; 
                dp[idx+1][1] += dp[idx][add];
            }       
        } 
    }
    dp[N][0] += dp[N-1][0];
    dp[N][0] += dp[N-1][1];
    
    cout << dp[N][0] << "\n";


}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}