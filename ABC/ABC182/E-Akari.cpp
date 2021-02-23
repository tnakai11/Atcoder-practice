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

// https://atcoder.jp/contests/abc182/tasks/abc182_e

// 気持ち
// 各電球から愚直に探索を生やすとたぶん間に合わない
// 各マスから探索を生やすのはどうか？
// (1500 + 1500) * 1500^2
// 微妙そう
// 各行・各列について往復走査するのはどうか
 // ( (1500 * 2) * 1500 ) * 2 = 3000^2 = 9 * 10^6
// たぶん行ける

int board[1505][1505]; // 0 は無情報、-1はブロック、1は明るい、2は灯り

void solve(){ 
    int H,W,N,M; cin >> H >> W >> N >> M;
    FILL2(board,H,W,0);
    REP(i,N){
        int a,b; cin >> a>> b;
        --a; --b;
        board[a][b] = 2;
    }
    REP(i,M){
        int c,d; cin >> c >> d;
        --c; --d;
        board[c][d] = -1;
    }
    // 列ごとに走査
    REP(i,H){
        bool existLight = false;
        REP(j,W){
            if(board[i][j]==-1){
                existLight = false;
            }else if(board[i][j]==2){
                existLight = true;
            }else if(existLight==true){
                board[i][j] = 1;
            }
        }
        existLight = false;
        REPR(j,W-1){
            if(board[i][j]==-1){
                existLight = false;
            }else if(board[i][j]==2){
                existLight = true;
            }else if(existLight==true){
                board[i][j] = 1;
            }
        }
    }
    // 行ごとに走査
    REP(j,W){
        bool existLight = false;
        REP(i,H){
            if(board[i][j]==-1){
                existLight = false;
            }else if(board[i][j]==2){
                existLight = true;
            }else if(existLight==true){
                board[i][j] = 1;
            }
        }
        existLight = false;
        REPR(i,H-1){
            if(board[i][j]==-1){
                existLight = false;
            }else if(board[i][j]==2){
                existLight = true;
            }else if(existLight==true){
                board[i][j] = 1;
            }
        }
    }
    // カウント
    int ans = 0;
    REP(i,H){
        REP(j,W){
            if(board[i][j]>=1){
                ++ans;
            }
        }
    }
    cout << ans <<  "\n";

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}