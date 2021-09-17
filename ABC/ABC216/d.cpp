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
// https://atcoder.jp/contests/abc216/tasks/abc216_d
// 操作順で詰みが発生するだろうか？
// A: 3
// B: 1
// C: 12
// D: 23
// 同色のボールは1組しかないので愚直に調べれば最終的には解ける
// 上から順に舐めればO(N+M)でいける？

// TLE
// 上手くいかないので解説を読む
// O(NM) になってたぽい

void solve(){ 
    int N,M; cin >> N >> M;
    queue<int> a[M]; // 筒を管理
    vector<int> index[N]; // 値 i が頭に存在する筒の位置を管理
    queue<int> done; // 2つ揃った色を管理
    // 筒にボールを込める
    REP(i,M){
        int K; cin >> K;
        REP(j,K){
            int e; cin >> e;
            --e;
            a[i].push(e);
        }
    }
    // 各筒の先頭の色を調べ位置をマッピングする
    REP(i,M){
        int e = a[i].front();
        index[ e ].emplace_back(i);
    }
    // 既にボールが2つ揃っている色をキューに詰める
    REP(i,N){
        if(index[i].size()==2){
            done.push(i);
        }
    }
    // 除去できるボールがある限り操作を続ける
    while(!done.empty()){
        int colorToRemove = done.front(); done.pop(); // 除去する色を取り出す
        for(int pos: index[colorToRemove]){ // 色に対応する筒を操作する
            a[pos].pop(); // ボールの除去
            if(a[pos].empty()) continue; // 筒が空になった

            int e = a[pos].front(); // 新しく生えた先頭の色を調べ位置をマッピング
            index[e].emplace_back(pos);
            // ボールが2つ揃った色はキューに詰める
            if( index[e].size()==2 ){
                done.push(e);
            }
        }
    }
    // 空になったか確認し答えを出力する
    string ans = Liny;
    REP(i,M){
        if(!a[i].empty()){
            ans = Linn;
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