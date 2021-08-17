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
// https://atcoder.jp/contests/typical90/tasks/typical90_f
// 全列挙は無理筋
// 最小のものだけを取ればよいので貪欲で O(N^2)?
// 最悪のシナリオは aaaaa~
// 各文字の候補は高々 N-K 個 
// 必要ステップは (N-K)*K = -(K-N/2) + (N/2)^2
// 最大 2.5 * 10^9 となりやや怪しいが通った
// 解説を読んでおく
// 前処理をすれば O(N count(alphabet) )
void solve(){ 
    int N,K; cin >> N >> K;
    string s; cin >> s;
    string ans;
    int pin = 0;
    int idx;
    while(ans.size()<K){
        idx = pin;
        int lim = N - (K-1) + ans.size();
        dprint(lim);
        while(idx<lim){
            if(s[idx]<s[pin]){
                pin = idx;
            }
            ++idx;
        }
        ans.push_back(s[pin]);
        ++pin;
    }
    cout << ans << '\n';
}
void solveAssumed(){
    int N,K; cin >> N >> K;
    string s; cin >> s;
    int table[N+1][30]; // idx 以右にある文字 c について一番左にあるものの位置
    FILL2(table,N+1,30,N+5);
    REPR(idx,N-1){
        for(int c=0;c<='z'-'a';++c){
            table[idx][c] = table[idx+1][c];
        }
        table[idx][(int)(s[idx]-'a')] = idx;
    }
    string ans;
    int pin = 0;
    while(ans.size()<K){
        int lim = N-1 - (K-1) + ans.size();
        for(int c=0;c<='z'-'a';++c){
            if(table[pin][c]<=lim){
                ans.push_back((char)('a'+c));
                pin = table[pin][c] + 1;
                break;
            }
        }
        dprint(ans);
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solveAssumed();
  return 0;
}