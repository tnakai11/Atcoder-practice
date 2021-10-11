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
// https://atcoder.jp/contests/abc218/tasks/abc218_c
// N が高々 200 なので回転4パターンの全探索でいけそう
// 90度回転
// (0.0) -> (N,0)
// (N,0) -> (N,N)
// (0,N) -> (0,0)
// (N,N) -> (0,N)
// (x,y) -> (N-y,x)
// 頭と左端を合わせて比較する
int N; 
string s[205];
string t[205];
char a[205][205];
char b[205][205];

// t を回転させる
void turn(){
    string temp[205];
    REP(i,N) temp[i] = t[i];
    REP(h,N){
        REP(w,N){
            t[h][w] = temp[w][N-1-h];
        }
    }
}

void solve(){ 
    cin >> N;
    CINA(s,N);
    CINA(t,N);
    // s の位置合わせ
    int sTop = -1;
    int sLeft = -1;
    REP(h,N){
        REP(w,N){
            if(s[h][w]=='#'){
                sTop = h;
                break;
            }
        }
        if(sTop>=0) break;
    }
    REP(w,N){
        REP(h,N){
            if(s[h][w]=='#'){
                sLeft = w;
                break;
            }
        }
        if(sLeft>=0) break;
    }
    FILL2(a,N,N,'.');
    for(int h=sTop;h<N;++h){
        for(int w=sLeft;w<N;++w){
            a[h-sTop][w-sLeft] = s[h][w];
        }
    }
    // s,tの比較
    string ans = Linn;
    REP(i,4){
        FILL2(b,N,N,'.');
        // t の位置合わせ
        if(i>0) turn();
        int tTop = -1;
        int tLeft = -1;
        REP(h,N){
            REP(w,N){
                if(t[h][w]=='#'){
                    tTop = h;
                    break;
                }
            }
            if(tTop>=0) break;
        }
        REP(w,N){
            REP(h,N){
                if(t[h][w]=='#'){
                    tLeft = w;
                    break;
                }
            }
            if(tLeft>=0) break;
        }
        for(int h=tTop;h<N;++h){
            for(int w=tLeft;w<N;++w){
                b[h-tTop][w-tLeft] = t[h][w];
            }
        }
        // if(DEBUG){
        //     dprint('t');
        //     REP(h,N){
        //         REP(w,N) cout << t[h][w];
        //         cout << '\n';
        //     }
        //     dprint('b');
        //     REP(h,N){
        //         REP(w,N) cout << b[h][w];
        //         cout << '\n';
        //     }
        //         cout << '\n';
        // }
        // 同じかチェック
        bool ok = true;
        REP(h,N){
            REP(w,N){
                if(a[h][w]!=b[h][w]){
                    ok = false;
                }
            }
        }
        if(ok){
            ans = Liny;
            break;
        }
    }
    cout << ans;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}