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

// https://atcoder.jp/contests/abc182/tasks/abc182_c

// 気持ち
// 3の倍数の判定条件を使えば
// O(桁数)で判定できそう
// ・3で割った余りが0の数はいくらあっても構わない
// ・余り1の数と余り2の数をニコイチで残せる
// ・余り1の数、余り2の数は3つあればセットにできる
// ・残し方に注意が必要
// ・はみ出た分を消して数が残ればOK
// ↑書こうとしたものの場合分けが面倒
// 答えは 0 or 1 or 2 なので全探索で済ませよう

void solve(){ 
    string s; cin >> s;
    int K = s.size();
    vector<int> a(K);
    int checkSum = 0;
    REP(i,K){
        a[i] = ctoi(s[i]);
        checkSum += a[i];
    }
    // 3の倍数だった
    if(checkSum%3==0){
        cout << 0 << "\n";
        return;
    }
    // これ以上減らせない
    if(K==1){ cout << -1 << "\n"; return;}

    // 1つ消せば行けた
    REP(i,K){
        if( (checkSum-a[i])%3 == 0 ){
            cout << 1  << "\n";
            return;
        }
    }
    // これ以上減らせない
    if(K==2){ cout << -1 << "\n"; return;}

    // 2つ消せば行けた
    REP(i,K){
        int temp = checkSum - a[i];
        for(int j=i+1;j<K;++j){
            if( (temp-a[j])%3 == 0 ){
                cout << 2 << "\n";
                return;
            }
        }
    }
    // 無理
    cout << -1 << "\n";
    return;
    
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}