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
// https://atcoder.jp/contests/abc219/tasks/abc219_d
// dpの気配を感じる
// dp[x][y]:たこ焼きを x 個以上、たいやきをy個以上食べるのに必要な弁当の個数
// x,y の取り得る値が大きいな...
// X 以上の値、Y 以上の値はそれぞれX,Yでまとめて構わないか
// dp 配列を全て踏んでも O(NXY) となり問題の制約では間に合う
// 同じ弁当でホップが重ならないよう大きな値から更新していく

// AC 
// 3次元配列 dp[N][X][Y] を使えば更新が楽だった

int dp[305][305];
void solve(){ 
    int N; cin >> N;
    int X,Y; cin >> X >> Y;
    FILL2(dp,X+1,Y+1,500);
    dp[0][0] = 0;
    REP(count,N){
        int A,B; cin >> A >> B;
        for(int x=X;x>=0;--x){
            int next_x = min(x + A,X);
            for(int y=Y;y>=0;--y){
                int next_y = min(y + B,Y);
                chmin(dp[next_x][next_y],dp[x][y] + 1);
            }
        }
    }
    int ans;
    if(dp[X][Y]<500){
        ans = dp[X][Y];
    }else{
        ans = -1;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}