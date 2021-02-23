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
using mint = modint1000000007;
// using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}

// https://atcoder.jp/contests/abc183/tasks/abc183_e

// 気持ち
// たぶんDP?
// もらうDPで解くとバグりそうなので配るDPで解く
// 愚直に書いたら TLE ...
// 累積和で何とか
// 縦方向、横方向、斜め方向について累積和を保持

struct cell{
    mint t = 0;
    mint y = 0;
    mint n = 0;
    mint v = 0;
};

string board[2005];
cell p[2005][2005];

void solve(){ 
    int H,W; cin >> H >> W;
    REP(i,H){
        cin >> board[i];
        board[i] += "#";
    }
    board[H] = string(W+1,'#');
    
    p[0][0] = {0,0,0,1};
    int l = 0;
    while(l<min(H,W)){
        if(board[l][l]=='.'){
            p[l][l].v += p[l][l].t;
            p[l][l].v += p[l][l].y;
            p[l][l].v += p[l][l].n;
            if(board[l+1][l]=='.'){
                p[l+1][l].t = p[l][l].t + p[l][l].v;
            }
            if(board[l][l+1]=='.'){
                p[l][l+1].y = p[l][l].y + p[l][l].v;
            }
            if(board[l+1][l+1]=='.'){
                p[l+1][l+1].n = p[l][l].n + p[l][l].v;
            }
        } 
        for(int i=l+1;i<H;++i){
            if(board[i][l]=='.'){
                p[i][l].v += p[i][l].t;
                p[i][l].v += p[i][l].y;
                p[i][l].v += p[i][l].n;
                if(board[i+1][l]=='.'){
                    p[i+1][l].t = p[i][l].t + p[i][l].v;
                }
                if(board[i][l+1]=='.'){
                    p[i][l+1].y = p[i][l].y + p[i][l].v;
                }
                if(board[i+1][l+1]=='.'){
                    p[i+1][l+1].n = p[i][l].n + p[i][l].v;
                }
            } 
        }
        for(int j=l+1;j<W;++j){
            if(board[l][j]=='.'){
                p[l][j].v += p[l][j].t;
                p[l][j].v += p[l][j].y;
                p[l][j].v += p[l][j].n;
                if(board[l+1][j]=='.'){
                    p[l+1][j].t = p[l][j].t + p[l][j].v;
                }
                if(board[l][j+1]=='.'){
                    p[l][j+1].y = p[l][j].y + p[l][j].v;
                }
                if(board[l+1][j+1]=='.'){
                    p[l+1][j+1].n = p[l][j].n + p[l][j].v;
                }
            } 
        }
        ++l;
    }
    if(DEBUG){
        REP(i,H){
            REP(j,W){
                cout << p[i][j].v.val() << " ";
            }
            cout << "\n";
        }
    }
    mint ans = p[H-1][W-1].v;
    cout << ans.val() << "\n";

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}