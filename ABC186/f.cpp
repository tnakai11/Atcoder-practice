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

// https://atcoder.jp/contests/abc186/tasks/abc186_f
// 気持ち
// 愚直に調べると最大 HW マス調べることになり厳しそう
// 障害物に注目すれば計算量が落ちそう
// 重複どうしよう

// 解説を見た
// 各行について上から侵入可能なマスの数を計上
// 各列について障害物が上位の行で登場したかをBITで管理
// 上に障害物がある && 左から侵入可能なマスを計上

// 扱う数が大きいと配列の確保に失敗するため注意

// 配列の名前を雑にするとバグるので注意

vector<int> yoko[200005];// h 行目にある障害物の列位置
vector<int> tate[200005];// w 列目にある障害物の行位置

fenwick_tree<int> fw(200005);

void solve(){
    int H,W,M; cin >> H >> W >> M;
    REP(i,M){
        int x,y; cin >> x >> y;
        yoko[ x ].push_back( y );
        tate[ y ].push_back( x );
    }
    for(int h=1;h<=H;++h){
        sort(ALL(yoko[h]));
        yoko[h].push_back(W+1);
    }
    for(int w=1;w<=W;++w){
        sort(ALL(tate[w]));
        tate[w].push_back(H+1);
    }

    ll ans = 0;
    // 上から侵入できるマスの数
    for(int w=1;w<yoko[1][0];++w){
        ans += tate[w][0]-1;
    }

    // 左からしか侵入できないマスの数
    // h=1
    for(int w=yoko[1][0];w<=W;++w){
        fw.add(w,1);
    }
    for(int h=2;h<tate[1][0];++h){
        ans += fw.sum(1,yoko[h][0]);
        for(int w:yoko[h]) { 
            if( fw.sum(w,w+1)==0 ){
                fw.add(w,1);
            }
        }
    }
    cout << ans << '\n';
}
    
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}