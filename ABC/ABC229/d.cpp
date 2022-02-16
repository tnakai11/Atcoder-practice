#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
using mint = modint998244353;
// const ll MOD = 1e9+7;
// using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc229/tasks/abc229_d
// 総当たると O(S_C_K) になりヤバい
// (P_1) C_1 (P_2) C_2 (P_3)
// P ... ポイント
// C ... コスト
// としてコストK以内で最大の sum(P) + sum(C) を得る問題と同じ?

// 勘が鈍っているので解説を読む
// 全消し可能な範囲を尺取り

void solve(){ 
    string s; cin >> s;
    int N = s.size();
    int K; cin >> K;
    int cumu[N+1];
    cumu[0] = 0;
    for(int i=1;i<=N;++i){
        if(s[i-1]=='.'){
            cumu[i] = cumu[i-1] + 1;
        }else{
            cumu[i] = cumu[i-1];
        }
    }
    int ans = 0;
    int right=0;
    for(int left=0;left<=N;++left){
        while(right<=N-1 && cumu[right+1]-cumu[left]<=K){
            ++right;
        }
        chmax(ans,right-left);
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}